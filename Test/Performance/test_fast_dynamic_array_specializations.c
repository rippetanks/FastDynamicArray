/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>
#include <stdlib.h>

#include "test.h"
#include "../../FastDynamicArray/FastDynamicArrayInt.h"
#include "../../FastDynamicArray/FastDynamicArrayChar.h"
#include "../../FastDynamicArray/FastDynamicArrayShortInt.h"
#include "../../FastDynamicArray/FastDynamicArrayLong.h"
#include "../../FastDynamicArray/FastDynamicArrayLongLong.h"
#include "../../FastDynamicArray/FastDynamicArrayFloat.h"
#include "../../FastDynamicArray/FastDynamicArrayDouble.h"
#include "../../FastDynamicArray/FastDynamicArrayLongDouble.h"

// INT
double _test_all_fast_dynamic_array_int(const int obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp;

    start = clock();

    DynamicVectorInt vector;
    dyvec_int_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_int_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_int_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_int_set(&vector, i, obj);

    dyvec_int_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// CHAR
double _test_all_fast_dynamic_array_char(const char obj, const int n) {
    long int i;
    clock_t start, end;
    char tmp;

    start = clock();

    DynamicVectorChar vector;
    dyvec_char_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_char_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_char_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_char_set(&vector, i, obj);

    dyvec_char_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// SHORT INT
double _test_all_fast_dynamic_array_shortint(const short int obj, const int n) {
    long int i;
    clock_t start, end;
    short int tmp;

    start = clock();

    DynamicVectorShortInt vector;
    dyvec_sint_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_sint_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_sint_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_sint_set(&vector, i, obj);

    dyvec_sint_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// LONG INT
double _test_all_fast_dynamic_array_longint(const long int obj, const int n) {
    long int i;
    clock_t start, end;
    long int tmp;

    start = clock();

    DynamicVectorLong vector;
    dyvec_long_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_long_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_long_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_long_set(&vector, i, obj);

    dyvec_long_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}


// LONG LONG INT
double _test_all_fast_dynamic_array_longlongint(const long long int obj, const int n) {
    long int i;
    clock_t start, end;
    long long int tmp;

    start = clock();

    DynamicVectorLongLong vector;
    dyvec_longlong_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_longlong_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_longlong_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_longlong_set(&vector, i, obj);

    dyvec_longlong_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// FLOAT
double _test_all_fast_dynamic_array_float(const float obj, const int n) {
    long int i;
    clock_t start, end;
    float tmp;

    start = clock();

    DynamicVectorFloat vector;
    dyvec_float_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_float_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_float_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_float_set(&vector, i, obj);

    dyvec_float_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// DOUBLE
double _test_all_fast_dynamic_array_double(const double obj, const int n) {
    long int i;
    clock_t start, end;
    double tmp;

    start = clock();

    DynamicVectorDouble vector;
    dyvec_double_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_double_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_double_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_double_set(&vector, i, obj);

    dyvec_double_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// LONG DOUBLE
double _test_all_fast_dynamic_array_longdouble(const long double obj, const int n) {
    long int i;
    clock_t start, end;
    long double tmp;

    start = clock();

    DynamicVectorLongDouble vector;
    dyvec_longdouble_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_longdouble_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = dyvec_longdouble_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_longdouble_set(&vector, i, obj);

    dyvec_longdouble_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}