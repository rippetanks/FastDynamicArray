/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYINT_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-06
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type int.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYINT_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorInt {
    struct _ItemDynamicVectorInt **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorInt;

typedef struct _ItemDynamicVectorInt {
    int item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorInt;

void dyvec_int_init(DynamicVectorInt*);

void dyvec_int_add(DynamicVectorInt*, int);

int dyvec_int_get(DynamicVectorInt*, long int);

void dyvec_int_set(DynamicVectorInt*, long int, int);

void dyvec_int_resize(DynamicVectorInt*, unsigned long int);

void dyvec_int_erase(DynamicVectorInt*, long int);

void dyvec_int_erase_interval(DynamicVectorInt*, long int, long int);

int dyvec_int_pop(DynamicVectorInt*);

void dyvec_int_push(DynamicVectorInt*, int);

void dyvec_int_free(DynamicVectorInt*);

#define FDA_INT_INIT(vec) DynamicVectorInt vec; dyvec_int_init(&vec)
#define FDA_INT_ADD(vec, item) dyvec_int_add(&vec, item)
#define FDA_INT_SET(vec, id, item) dyvec_int_set(&vec, id, item)
#define FDA_INT_GET(vec, id) dyvec_int_get(&vec, id)
#define FDA_INT_ERASE(vec, id) dyvec_int_erase(&vec, id)
#define FDA_INT_POP(vec) dyvec_int_pop(&vec)
#define FDA_INT_PUSH(vec, item) dyvec_int_push(&vec, item)
#define FDA_INT_FREE(vec) dyvec_int_free(&vec)

#define FDA_UINT_INIT(vec) DynamicVectorInt vec; dyvec_int_init(&vec)
#define FDA_UINT_ADD(vec, item) dyvec_int_add(&vec, (unsigned int) item)
#define FDA_UINT_SET(vec, id, item) dyvec_int_set(&vec, id, (unsigned int) item)
#define FDA_UINT_GET(vec, id) (unsigned int) dyvec_int_get(&vec, id)
#define FDA_UINT_ERASE(vec, id) dyvec_int_erase(&vec, id)
#define FDA_UINT_POP(vec) (unsigned int) dyvec_int_pop(&vec)
#define FDA_UINT_PUSH(vec, item) dyvec_int_push(&vec, (unsigned int) item)
#define FDA_UINT_FREE(vec) dyvec_int_free(&vec)

#define FDA_SINT_INIT(vec) DynamicVectorInt vec; dyvec_int_init(&vec)
#define FDA_SINT_ADD(vec, item) dyvec_int_add(&vec, (signed int) item)
#define FDA_SINT_SET(vec, id, item) dyvec_int_set(&vec, id, (signed int) item)
#define FDA_SINT_GET(vec, id) (signed int) dyvec_int_get(&vec, id)
#define FDA_SINT_ERASE(vec, id) dyvec_int_erase(&vec, id)
#define FDA_SINT_POP(vec) (signed int) dyvec_int_pop(&vec)
#define FDA_SINT_PUSH(vec, item) dyvec_int_push(&vec, (signed int) item)
#define FDA_SINT_FREE(vec) dyvec_int_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYINT_H
