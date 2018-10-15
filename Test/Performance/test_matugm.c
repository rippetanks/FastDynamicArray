/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>
#include <stdlib.h>

#include "test.h"

#include "../../Other/Matugm/Matugm.h"

static ma_ArrayData *v = NULL;

void* _get_matugm() {
    if(v == NULL) {
        v = ma_initArray();
    }
    return v;
}

void _clear_matugm() {
    free(v->pointer);
    free(v);
    v = NULL;
}

// ALL
double _test_all_matugm(const int obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp = 0;
    start = clock();

    ma_ArrayData *array;
    array = ma_initArray();

    // add
    for(i = 0; i < n; i++)
        ma_addElement(array, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = ma_getElement(array, i);

    // write
    for(i = 0; i < n; i++)
        array->pointer[i] = tmp;

    free(array->pointer);
    free(array);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// INSERT
_TestResult _test_insert_matugm(const int obj, const int n, void *const a) {
    long int i;
    clock_t start, end;

    ma_ArrayData *array = (ma_ArrayData*)a;
    start = clock();

    // add
    for(i = 0; i < n; i++)
        ma_addElement(array, obj);

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = array->size - array->counter;
    return result;
}

// READ
double _test_read_matugm(const int n, void *const a) {
    long int i;
    clock_t start, end;
    int tmp;

    ma_ArrayData *array = (ma_ArrayData*)a;
    start = clock();

    // read
    for(i = 0; i < n; i++)
        tmp = ma_getElement(array, i);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_matugm(const int obj, const int n, void *const a) {
    long int i;
    clock_t start, end;

    ma_ArrayData *array = (ma_ArrayData*)a;
    start = clock();

    // write
    for(i = 0; i < n; i++)
        array->pointer[i] = obj;

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}