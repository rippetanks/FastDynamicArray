/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "unit_test.h"
#include "../../FastDynamicArray/FastDynamicArrayDouble.h"
#include "unity.h"

void utest_double_init() {
    DynamicVectorDouble vector;
    dyvec_double_init(&vector);

    TEST_ASSERT_EQUAL_INT32(0, vector.size);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);
    TEST_ASSERT_NOT_NULL(vector.vectors);

    dyvec_double_free(&vector);
}

void utest_double_insert_read_write() {
    TEST_IGNORE();
    DynamicVectorDouble vector;
    int i;
    double x = 50, y = 100;

    dyvec_double_init(&vector);

    for(i = 0; i < _UNIT_TEST_N; i++)
        dyvec_double_add(&vector, x);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);
    TEST_ASSERT_EQUAL_INT32(vector.block * DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);

    for(i = 0; i < _UNIT_TEST_N; i++)
        TEST_ASSERT_EQUAL_DOUBLE(x, dyvec_double_get(&vector, i));
    for(i = 0; i < _UNIT_TEST_N; i++)
        if(i % 2 == 0)
            dyvec_double_set(&vector, i, y);
    for(i = 0; i < _UNIT_TEST_N; i++)
        if(i % 2 == 0)
            TEST_ASSERT_EQUAL_DOUBLE(y, dyvec_double_get(&vector, i));
        else
            TEST_ASSERT_EQUAL_DOUBLE(x, dyvec_double_get(&vector, i));

    dyvec_double_free(&vector);
}

void utest_double_insert_resize() {
    DynamicVectorDouble vector;
    int i;
    double x = 50;

    dyvec_double_init(&vector);

    for(i = 0; i < _UNIT_TEST_N; i++)
        dyvec_double_add(&vector, x);

    dyvec_double_resize(&vector, _UNIT_TEST_N * 2);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N * 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);
    TEST_ASSERT_EQUAL_INT32((_UNIT_TEST_N * 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1) * DYNAMIC_ARRAY_BLOCK_SIZE, vector.capacity);

    dyvec_double_resize(&vector, _UNIT_TEST_N / 2);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / 2, vector.size);
    TEST_ASSERT_EQUAL_INT32(_UNIT_TEST_N / 2 / DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.block);

    dyvec_double_resize(&vector, 0);
    TEST_ASSERT_EQUAL_INT32(2500, vector.size);
    TEST_ASSERT_EQUAL_INT32(3, vector.block);
    TEST_ASSERT_EQUAL_INT32(3072, vector.capacity);

    dyvec_double_free(&vector);
}

void utest_double_erase() {
    DynamicVectorDouble vector;
    int i;
    double x = 50;

    dyvec_double_init(&vector);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE + 1; i++)
        dyvec_double_add(&vector, x);

    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.size);
    TEST_ASSERT_EQUAL_INT32(2, vector.block);

    dyvec_double_erase(&vector, vector.size - 1);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE - 10; i++)
        dyvec_double_erase(&vector, 0);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);

    dyvec_double_free(&vector);
}

void utest_double_erase_interval() {
    DynamicVectorDouble vector;
    int i;
    double x = 50;

    dyvec_double_init(&vector);

    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE; i++)
        dyvec_double_add(&vector, x);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);

    dyvec_double_erase_interval(&vector, 0, DYNAMIC_ARRAY_BLOCK_SIZE / 2);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE / 2, vector.size);

    dyvec_double_free(&vector);
}

void utest_double_push_pop() {
    TEST_IGNORE();
    DynamicVectorDouble vector;
    int i;
    double x = 50;

    dyvec_double_init(&vector);
    dyvec_double_push(&vector, x);
    TEST_ASSERT_EQUAL_INT32(1, vector.size);
    TEST_ASSERT_EQUAL_DOUBLE(x, dyvec_double_pop(&vector));
    for(i = 0; i <= DYNAMIC_ARRAY_BLOCK_SIZE; i++)
        dyvec_double_push(&vector, x);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE + 1, vector.size);
    dyvec_double_pop(&vector);
    TEST_ASSERT_EQUAL_INT32(DYNAMIC_ARRAY_BLOCK_SIZE, vector.size);
    for(i = 0; i < DYNAMIC_ARRAY_BLOCK_SIZE - 10; i++)
        dyvec_double_pop(&vector);
    TEST_ASSERT_EQUAL_INT32(1, vector.block);
}

void utest_double_free() {
    DynamicVectorDouble vector;
    dyvec_double_init(&vector);
    dyvec_double_free(&vector);
}

