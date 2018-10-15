/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_FASTDYNAMICARRAYCHAR_H
/**
 *
 * \author S. Martelli
 * \date 2018-10-07
 * \brief High performance dynamic vector with minimal memory waste
 * \see https://github.com/rippetanks
 *
 *  This implementation manages a high-performance variable-size vector minimizing waste of memory.
 *  Specialization for type char.
 */
#define DYNAMIC_ARRAY_FASTDYNAMICARRAYCHAR_H

#include "FastDynamicArray.h"

typedef struct DynamicVectorChar {
    struct _ItemDynamicVectorChar **vectors;
    unsigned long int block;
    unsigned long int capacity;
    unsigned long int size;
} DynamicVectorChar;

typedef struct _ItemDynamicVectorChar {
    char item[DYNAMIC_ARRAY_BLOCK_SIZE];
} _ItemDynamicVectorChar;

void dyvec_char_init(DynamicVectorChar*);

void dyvec_char_add(DynamicVectorChar*, char);

char dyvec_char_get(DynamicVectorChar*, long int);

void dyvec_char_set(DynamicVectorChar*, long int, char);

void dyvec_char_resize(DynamicVectorChar*, unsigned long int);

void dyvec_char_erase(DynamicVectorChar*, long int);

void dyvec_char_erase_interval(DynamicVectorChar*, long int, long int);

char dyvec_char_pop(DynamicVectorChar*);

void dyvec_char_push(DynamicVectorChar*, char);

void dyvec_char_free(DynamicVectorChar*);

#define FDA_CHAR_INIT(vec) DynamicVectorChar vec; dyvec_char_init(&vec)
#define FDA_CHAR_ADD(vec, item) dyvec_char_add(&vec, item)
#define FDA_CHAR_SET(vec, id, item) dyvec_char_set(&vec, id, item)
#define FDA_CHAR_GET(vec, id) dyvec_char_get(&vec, id)
#define FDA_CHAR_ERASE(vec, id) dyvec_char_erase(&vec, id)
#define FDA_CHAR_POP(vec) dyvec_char_pop(&vec)
#define FDA_CHAR_PUSH(vec, item) dyvec_char_push(&vec, item)
#define FDA_CHAR_FREE(vec) dyvec_char_free(&vec)

#define FDA_UCHAR_INIT(vec) DynamicVectorChar vec; dyvec_char_init(&vec)
#define FDA_UCHAR_ADD(vec, item) dyvec_char_add(&vec, (char) item)
#define FDA_UCHAR_SET(vec, id, item) dyvec_char_set(&vec, id, (char) item)
#define FDA_UCHAR_GET(vec, id) (unsigned char) dyvec_char_get(&vec, id)
#define FDA_UCHAR_ERASE(vec, id) dyvec_char_erase(&vec, id)
#define FDA_UCHAR_POP(vec) (unsigned char) dyvec_char_pop(&vec)
#define FDA_UCHAR_PUSH(vec, item) dyvec_char_push(&vec, (char) item)
#define FDA_UCHAR_FREE(vec) dyvec_char_free(&vec)

#define FDA_SCHAR_INIT(vec) DynamicVectorChar vec; dyvec_char_init(&vec)
#define FDA_SCHAR_ADD(vec, item) dyvec_char_add(&vec, (char) item)
#define FDA_SCHAR_SET(vec, id, item) dyvec_char_set(&vec, id, (char) item)
#define FDA_SCHAR_GET(vec, id) (signed char) dyvec_char_get(&vec, id)
#define FDA_SCHAR_ERASE(vec, id) dyvec_char_erase(&vec, id)
#define FDA_SCHAR_POP(vec) (signed char) dyvec_char_pop(&vec)
#define FDA_SCHAR_PUSH(vec, item) dyvec_char_push(&vec, (char) item)
#define FDA_SCHAR_FREE(vec) dyvec_char_free(&vec)

#endif //DYNAMIC_ARRAY_FASTDYNAMICARRAYCHAR_H
