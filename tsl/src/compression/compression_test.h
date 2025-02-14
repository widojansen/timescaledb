/*
 * This file and its contents are licensed under the Timescale License.
 * Please see the included NOTICE for copyright information and
 * LICENSE-TIMESCALE for a copy of the license.
 */
#pragma once

#include "compression.h"

int decompress_ARRAY_TEXT(const uint8 *Data, size_t Size, bool bulk);

int decompress_DICTIONARY_TEXT(const uint8 *Data, size_t Size, bool bulk);

const CompressionAlgorithmDefinition *algorithm_definition(CompressionAlgorithm algo);
