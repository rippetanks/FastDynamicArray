/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGDOUBLE_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-11
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type long double.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGDOUBLE_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorLongDouble {
    struct _ItemDynamicVectorLongDouble **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorLongDouble;

typedef struct _ItemDynamicVectorLongDouble {
    long double item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorLongDouble;

void dyvec_longdouble_init(DynamicVectorLongDouble*);

void dyvec_longdouble_add(DynamicVectorLongDouble*, long double);

long double dyvec_longdouble_get(DynamicVectorLongDouble*, long int);

void dyvec_longdouble_set(DynamicVectorLongDouble*, long int, long double);

void dyvec_longdouble_resize(DynamicVectorLongDouble*, unsigned long int);

void dyvec_longdouble_erase(DynamicVectorLongDouble*, long int);

void dyvec_longdouble_erase_interval(DynamicVectorLongDouble*, long int, long int);

long double dyvec_longdouble_pop(DynamicVectorLongDouble*);

void dyvec_longdouble_push(DynamicVectorLongDouble*, long double);

void dyvec_longdouble_free(DynamicVectorLongDouble*);

#define FDA_LONGDOUBLE_INIT(vec) DynamicVectorLongDouble vec; dyvec_longdouble_init(&vec)
#define FDA_LONGDOUBLE_ADD(vec, item) dyvec_longdouble_add(&vec, item)
#define FDA_LONGDOUBLE_SET(vec, id, item) dyvec_longdouble_set(&vec, id, item)
#define FDA_LONGDOUBLE_GET(vec, id) dyvec_longdouble_get(&vec, id)
#define FDA_LONGDOUBLE_ERASE(vec, id) dyvec_longdouble_erase(&vec, id)
#define FDA_LONGDOUBLE_POP(vec) dyvec_longdouble_pop(&vec)
#define FDA_LONGDOUBLE_PUSH(vec, item) dyvec_longdouble_push(&vec, item)
#define FDA_LONGDOUBLE_FREE(vec) dyvec_longdouble_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGDOUBLE_H
