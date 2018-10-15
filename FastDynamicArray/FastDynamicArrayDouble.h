/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYDOUBLE_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-11
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type double.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYDOUBLE_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorDouble {
    struct _ItemDynamicVectorDouble **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorDouble;

typedef struct _ItemDynamicVectorDouble {
    double item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorDouble;

void dyvec_double_init(DynamicVectorDouble*);

void dyvec_double_add(DynamicVectorDouble*, double);

double dyvec_double_get(DynamicVectorDouble*, long int);

void dyvec_double_set(DynamicVectorDouble*, long int, double);

void dyvec_double_resize(DynamicVectorDouble*, unsigned long int);

void dyvec_double_erase(DynamicVectorDouble*, long int);

void dyvec_double_erase_interval(DynamicVectorDouble*, long int, long int);

double dyvec_double_pop(DynamicVectorDouble*);

void dyvec_double_push(DynamicVectorDouble*, double);

void dyvec_double_free(DynamicVectorDouble*);

#define FDA_DOUBLE_INIT(vec) DynamicVectorDouble vec; dyvec_double_init(&vec)
#define FDA_DOUBLE_ADD(vec, item) dyvec_double_add(&vec, item)
#define FDA_DOUBLE_SET(vec, id, item) dyvec_double_set(&vec, id, item)
#define FDA_DOUBLE_GET(vec, id) dyvec_double_get(&vec, id)
#define FDA_DOUBLE_ERASE(vec, id) dyvec_double_erase(&vec, id)
#define FDA_DOUBLE_POP(vec) dyvec_double_pop(&vec)
#define FDA_DOUBLE_PUSH(vec, item) dyvec_double_push(&vec, item)
#define FDA_DOUBLE_FREE(vec) dyvec_double_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYDOUBLE_H
