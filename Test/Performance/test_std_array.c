/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>

#include "test.h"

static int std_array[_MAX];

void* _get_stdarray() {
    return std_array;
}

// ALL
double _test_all_std_array(const int obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp = 0;
    int stdArray[_MAX];
    start = clock();

    // add
    for(i = 0; i < n; i++)
        stdArray[i] =  obj;

    // read
    for(i = 0; i < n; i++)
        tmp = stdArray[i];

    // write
    for(i = 0; i < n; i++)
        stdArray[i] = tmp;

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// INSERT
_TestResult _test_insert_std_array(const int obj, const int n, void *const a) {
    long int i;
    clock_t start, end;
    int *stdArray = (int*)a;
    start = clock();

    // add
    for(i = 0; i < n; i++)
        stdArray[i] =  obj;

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = _MAX - n;
    return result;
}

// READ
double _test_read_std_array(const int n, void *const a) {
    long int i;
    clock_t start, end;
    int tmp;
    int *stdArray = (int*)a;
    start = clock();

    // read
    for(i = 0; i < n; i++)
        tmp = stdArray[i];

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_std_array(const int obj, const int n, void *const a) {
    long int i;
    clock_t start, end;
    int *stdArray = (int*)a;
    start = clock();

    // write
    for(i = 0; i < n; i++)
        stdArray[i] = obj;

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}