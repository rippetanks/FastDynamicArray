/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGLONG_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-11
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type long long int.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGLONG_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorLongLong {
    struct _ItemDynamicVectorLongLong **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorLongLong;

typedef struct _ItemDynamicVectorLongLong {
    long long int item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorLongLong;

void dyvec_longlong_init(DynamicVectorLongLong*);

void dyvec_longlong_add(DynamicVectorLongLong*, long long);

long long dyvec_longlong_get(DynamicVectorLongLong*, long int);

void dyvec_longlong_set(DynamicVectorLongLong*, long int, long long);

void dyvec_longlong_resize(DynamicVectorLongLong*, unsigned long int);

void dyvec_longlong_erase(DynamicVectorLongLong*, long int);

void dyvec_longlong_erase_interval(DynamicVectorLongLong*, long int, long int);

long long dyvec_longlong_pop(DynamicVectorLongLong*);

void dyvec_longlong_push(DynamicVectorLongLong*, long long);

void dyvec_longlong_free(DynamicVectorLongLong*);

#define FDA_LONGLONG_INIT(vec) DynamicVectorLongLong vec; dyvec_longlong_init(&vec)
#define FDA_LONGLONG_ADD(vec, item) dyvec_longlong_add(&vec, item)
#define FDA_LONGLONG_SET(vec, id, item) dyvec_longlong_set(&vec, id, item)
#define FDA_LONGLONG_GET(vec, id) dyvec_longlong_get(&vec, id)
#define FDA_LONGLONG_ERASE(vec, id) dyvec_longlong_erase(&vec, id)
#define FDA_LONGLONG_POP(vec) dyvec_longlong_pop(&vec)
#define FDA_LONGLONG_PUSH(vec, item) dyvec_longlong_push(&vec, item)
#define FDA_LONGLONG_FREE(vec) dyvec_longlong_free(&vec)

#define FDA_ULONGLONG_INIT(vec) DynamicVectorLongLong vec; dyvec_longlong_init(&vec)
#define FDA_ULONGLONG_ADD(vec, item) dyvec_longlong_add(&vec, (long long) item)
#define FDA_ULONGLONG_SET(vec, id, item) dyvec_longlong_set(&vec, id, (long long) item)
#define FDA_ULONGLONG_GET(vec, id) (unsigned long long) dyvec_longlong_get(&vec, id)
#define FDA_ULONGLONG_ERASE(vec, id) dyvec_longlong_erase(&vec, id)
#define FDA_ULONGLONG_POP(vec) (unsigned long long) dyvec_longlong_pop(&vec)
#define FDA_ULONGLONG_PUSH(vec, item) dyvec_longlong_push(&vec, (long long) item)
#define FDA_ULONGLONG_FREE(vec) dyvec_longlong_free(&vec)

#define FDA_SLONGLONG_INIT(vec) DynamicVectorLongLong vec; dyvec_longlong_init(&vec)
#define FDA_SLONGLONG_ADD(vec, item) dyvec_longlong_add(&vec, (long long) item)
#define FDA_SLONGLONG_SET(vec, id, item) dyvec_longlong_set(&vec, id, (long long) item)
#define FDA_SLONGLONG_GET(vec, id) (signed long long) dyvec_longlong_get(&vec, id)
#define FDA_SLONGLONG_ERASE(vec, id) dyvec_longlong_erase(&vec, id)
#define FDA_SLONGLONG_POP(vec) (signed long long) dyvec_longlong_pop(&vec)
#define FDA_SLONGLONG_PUSH(vec, item) dyvec_longlong_push(&vec, (long long) item)
#define FDA_SLONGLONG_FREE(vec) dyvec_longlong_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYLONGLONG_H
