/*
 * This file and its contents are licensed under the Timescale License.
 * Please see the included NOTICE for copyright information and
 * LICENSE-TIMESCALE for a copy of the license.
 */

/*
 * Functions for working with vectorized predicates.
 */

#include <postgres.h>

#include <utils/date.h>
#include <utils/fmgroids.h>

#include "compression/arrow_c_data_interface.h"

#include "vector_predicates.h"

#include "compat/compat.h"
#include "compression/compression.h"
#include "debug_assert.h"

/*
 * We include all implementations of vector-const predicates here. No separate
 * declarations for them to reduce the amount of macro template magic.
 */
#include "pred_vector_const_arithmetic_all.c"

/*
 * Look up the vectorized implementation for a Postgres predicate, specified by
 * its Oid in pg_proc. Note that this Oid is different from the opcode.
 */
VectorPredicate *
get_vector_const_predicate(Oid pg_predicate)
{
	switch (pg_predicate)
	{
#define GENERATE_DISPATCH_TABLE
#include "pred_vector_const_arithmetic_all.c"
#undef GENERATE_DISPATCH_TABLE
	}
	return NULL;
}
