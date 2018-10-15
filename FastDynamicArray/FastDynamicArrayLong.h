/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYLONG_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-11
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type long int.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYLONG_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorLong {
    struct _ItemDynamicVectorLong **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorLong;

typedef struct _ItemDynamicVectorLong {
    long int item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorLong;

void dyvec_long_init(DynamicVectorLong*);

void dyvec_long_add(DynamicVectorLong*, long);

long dyvec_long_get(DynamicVectorLong*, long int);

void dyvec_long_set(DynamicVectorLong*, long int, long);

void dyvec_long_resize(DynamicVectorLong*, unsigned long int);

void dyvec_long_erase(DynamicVectorLong*, long int);

void dyvec_long_erase_interval(DynamicVectorLong*, long int, long int);

long dyvec_long_pop(DynamicVectorLong*);

void dyvec_long_push(DynamicVectorLong*, long);

void dyvec_long_free(DynamicVectorLong*);

#define FDA_LONG_INIT(vec) DynamicVectorLong vec; dyvec_long_init(&vec)
#define FDA_LONG_ADD(vec, item) dyvec_long_add(&vec, item)
#define FDA_LONG_SET(vec, id, item) dyvec_long_set(&vec, id, item)
#define FDA_LONG_GET(vec, id) dyvec_long_get(&vec, id)
#define FDA_LONG_ERASE(vec, id) dyvec_long_erase(&vec, id)
#define FDA_LONG_POP(vec) dyvec_long_pop(&vec)
#define FDA_LONG_PUSH(vec, item) dyvec_long_push(&vec, item)
#define FDA_LONG_FREE(vec) dyvec_long_free(&vec)

#define FDA_ULONG_INIT(vec) DynamicVectorLong vec; dyvec_long_init(&vec)
#define FDA_ULONG_ADD(vec, item) dyvec_long_add(&vec, (long) item)
#define FDA_ULONG_SET(vec, id, item) dyvec_long_set(&vec, id, (long) item)
#define FDA_ULONG_GET(vec, id) (unsigned long) dyvec_long_get(&vec, id)
#define FDA_ULONG_ERASE(vec, id) dyvec_long_erase(&vec, id)
#define FDA_ULONG_POP(vec) (unsigned long) dyvec_long_pop(&vec)
#define FDA_ULONG_PUSH(vec, item) dyvec_long_push(&vec, (long) item)
#define FDA_ULONG_FREE(vec) dyvec_long_free(&vec)

#define FDA_SLONG_INIT(vec) DynamicVectorLong vec; dyvec_long_init(&vec)
#define FDA_SLONG_ADD(vec, item) dyvec_long_add(&vec, (long) item)
#define FDA_SLONG_SET(vec, id, item) dyvec_long_set(&vec, id, (long) item)
#define FDA_SLONG_GET(vec, id) (signed long) dyvec_long_get(&vec, id)
#define FDA_SLONG_ERASE(vec, id) dyvec_long_erase(&vec, id)
#define FDA_SLONG_POP(vec) (signed long) dyvec_long_pop(&vec)
#define FDA_SLONG_PUSH(vec, item) dyvec_long_push(&vec, (long) item)
#define FDA_SLONG_FREE(vec) dyvec_long_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYLONG_H
