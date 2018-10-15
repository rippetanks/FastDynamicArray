/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYSHORTINT_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-10
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type short int.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYSHORTINT_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorShortInt {
    struct _ItemDynamicVectorShortInt **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorShortInt;

typedef struct _ItemDynamicVectorShortInt {
    short int item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorShortInt;

void dyvec_sint_init(DynamicVectorShortInt*);

void dyvec_sint_add(DynamicVectorShortInt*, short int);

short int dyvec_sint_get(DynamicVectorShortInt*, long int);

void dyvec_sint_set(DynamicVectorShortInt*, long int, short int);

void dyvec_sint_resize(DynamicVectorShortInt*, unsigned long int);

void dyvec_sint_erase(DynamicVectorShortInt*, long int);

void dyvec_sint_erase_interval(DynamicVectorShortInt*, long int, long int);

short int dyvec_sint_pop(DynamicVectorShortInt*);

void dyvec_sint_push(DynamicVectorShortInt*, short int);

void dyvec_sint_free(DynamicVectorShortInt*);

#define FDA_SHORTINT_INIT(vec) DynamicVectorShortInt vec; dyvec_sint_init(&vec)
#define FDA_SHORTINT_ADD(vec, item) dyvec_sint_add(&vec, item)
#define FDA_SHORTINT_SET(vec, id, item) dyvec_sint_set(&vec, id, item)
#define FDA_SHORTINT_GET(vec, id) dyvec_sint_get(&vec, id)
#define FDA_SHORTINT_ERASE(vec, id) dyvec_sint_erase(&vec, id)
#define FDA_SHORTINT_POP(vec) dyvec_sint_pop(&vec)
#define FDA_SHORTINT_PUSH(vec, item) dyvec_sint_push(&vec, item)
#define FDA_SHORTINT_FREE(vec) dyvec_sint_free(&vec)

#define FDA_SHORTSINT_INIT(vec) DynamicVectorShortInt vec; dyvec_sint_init(&vec)
#define FDA_SHORTSINT_ADD(vec, item) dyvec_sint_add(&vec, (short int) item)
#define FDA_SHORTSINT_SET(vec, id, item) dyvec_sint_set(&vec, id, (short int) item)
#define FDA_SHORTSINT_GET(vec, id) (signed short int) dyvec_sint_get(&vec, id)
#define FDA_SHORTSINT_ERASE(vec, id) dyvec_sint_erase(&vec, id)
#define FDA_SHORTSINT_POP(vec) (signed short int) dyvec_sint_pop(&vec)
#define FDA_SHORTSINT_PUSH(vec, item) dyvec_sint_push(&vec, (short int) item)
#define FDA_SHORTSINT_FREE(vec) dyvec_sint_free(&vec)

#define FDA_SHORTUINT_INIT(vec) DynamicVectorShortInt vec; dyvec_sint_init(&vec)
#define FDA_SHORTUINT_ADD(vec, item) dyvec_sint_add(&vec, (short int) item)
#define FDA_SHORTUINT_SET(vec, id, item) dyvec_sint_set(&vec, id, (short int) item)
#define FDA_SHORTUINT_GET(vec, id) (unsigned short int) dyvec_sint_get(&vec, id)
#define FDA_SHORTUINT_ERASE(vec, id) dyvec_sint_erase(&vec, id)
#define FDA_SHORTUINT_POP(vec) (unsigned short int) dyvec_sint_pop(&vec)
#define FDA_SHORTUINT_PUSH(vec, item) dyvec_sint_push(&vec, (short int) item)
#define FDA_SHORTUINT_FREE(vec) dyvec_sint_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYSHORTINT_H
