/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYFLOAT_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-11
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type float.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYFLOAT_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorFloat {
    struct _ItemDynamicVectorFloat **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorFloat;

typedef struct _ItemDynamicVectorFloat {
    float item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorFloat;

void dyvec_float_init(DynamicVectorFloat*);

void dyvec_float_add(DynamicVectorFloat*, float);

float dyvec_float_get(DynamicVectorFloat*, long int);

void dyvec_float_set(DynamicVectorFloat*, long int, float);

void dyvec_float_resize(DynamicVectorFloat*, unsigned long int);

void dyvec_float_erase(DynamicVectorFloat*, long int);

void dyvec_float_erase_interval(DynamicVectorFloat*, long int, long int);

float dyvec_float_pop(DynamicVectorFloat*);

void dyvec_float_push(DynamicVectorFloat*, float);

void dyvec_float_free(DynamicVectorFloat*);

#define FDA_FLOAT_INIT(vec) DynamicVectorFloat vec; dyvec_float_init(&vec)
#define FDA_FLOAT_ADD(vec, item) dyvec_float_add(&vec, item)
#define FDA_FLOAT_SET(vec, id, item) dyvec_float_set(&vec, id, item)
#define FDA_FLOAT_GET(vec, id) dyvec_float_get(&vec, id)
#define FDA_FLOAT_ERASE(vec, id) dyvec_float_erase(&vec, id)
#define FDA_FLOAT_POP(vec) dyvec_float_pop(&vec)
#define FDA_FLOAT_PUSH(vec, item) dyvec_float_push(&vec, item)
#define FDA_FLOAT_FREE(vec) dyvec_float_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYFLOAT_H
