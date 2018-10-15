/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "unit_test.h"
#include "../../FastDynamicArray/FastDynamicArrayChar.h"
#include "unity.h"

void utest_char_init() {
    DynamicVectorChar vector;
    dyvec_char_init(&vector);

    TEST_ASSERT_EQUAL_INT32(0, vector.size);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);
    TEST_ASSERT_NOT_NULL(vector.vectors);

    dyvec_char_free(&vector);
}

void utest_char_insert_read_write() {
    DynamicVectorChar vector;
    int i;
    char x = 50, y = 100;

    dyvec_char_init(&vector);

    for(i = 0; i < _UNIT_TEST_N; i++)
        dyvec_char_add(&vector, x);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);
    TEST_ASSERT_EQUAL_INT32(vector.block * DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);

    for(i = 0; i < _UNIT_TEST_N; i++)
        TEST_ASSERT_EQUAL_INT8(x, dyvec_char_get(&vector, i));
    for(i = 0; i < _UNIT_TEST_N; i++)
        if(i % 2 == 0)
            dyvec_char_set(&vector, i, y);
    for(i = 0; i < _UNIT_TEST_N; i++)
        if(i % 2 == 0)
            TEST_ASSERT_EQUAL_INT8(y, dyvec_char_get(&vector, i));
        else
            TEST_ASSERT_EQUAL_INT8(x, dyvec_char_get(&vector, i));

    dyvec_char_free(&vector);
}

void utest_char_insert_resize() {
    DynamicVectorChar vector;
    int i;
    char x = 50;

    dyvec_char_init(&vector);

    for(i = 0; i < _UNIT_TEST_N; i++)
        dyvec_char_add(&vector, x);

    dyvec_char_resize(&vector, _UNIT_TEST_N * 2);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N * 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);
    TEST_ASSERT_EQUAL_INT32((_UNIT_TEST_N * 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1) * DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);

    dyvec_char_resize(&vector, _UNIT_TEST_N / 2);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / 2, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);

    dyvec_char_resize(&vector, 0);
    TEST_ASSERT_EQUAL_INT32(2500, vector.size);
    TEST_ASSERT_EQUAL_INT32(3, vector.block);
    TEST_ASSERT_EQUAL_INT32(3072, vector.capacity);

    dyvec_char_free(&vector);
}

void utest_char_erase() {
    DynamicVectorChar vector;
    int i;
    char x = 50;

    dyvec_char_init(&vector);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE + 1; i++)
        dyvec_char_add(&vector, x);

    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.size);
    TEST_ASSERT_EQUAL_INT32(2, vector.block);

    dyvec_char_erase(&vector, vector.size - 1);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE - 10; i++)
        dyvec_char_erase(&vector, 0);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);

    dyvec_char_free(&vector);
}

void utest_char_erase_interval() {
    DynamicVectorChar vector;
    int i;
    char x = 50;

    dyvec_char_init(&vector);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE; i++)
        dyvec_char_add(&vector, x);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);

    dyvec_char_erase_interval(&vector, 0, DYNAMIC_ARRAY_BLOCK_SIZE / 2);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE / 2, vector.size);

    dyvec_char_free(&vector);
}

void utest_char_push_pop() {
    DynamicVectorChar vector;
    int i;
    char x = 50;

    dyvec_char_init(&vector);
    dyvec_char_push(&vector, x);
    TEST_ASSERT_EQUAL_INT32(1, vector.size);
    TEST_ASSERT_EQUAL_INT8(x, dyvec_char_pop(&vector));
    for(i = 0; i <= DYNAMIC_ARRAY_BLOCK_SIZE; i++)
        dyvec_char_push(&vector, x);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.size);
    dyvec_char_pop(&vector);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);
    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE - 10; i++)
        dyvec_char_pop(&vector);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);
}

void utest_char_free() {
    DynamicVectorChar vector;
    dyvec_char_init(&vector);
    dyvec_char_free(&vector);
}

