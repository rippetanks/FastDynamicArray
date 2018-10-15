/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>

#include "test.h"
#include "../../Other/StackOverflow/StackOverflow.h"

static so_Array *v = NULL;

void* _get_stackoverflow() {
    if(v == NULL) {
        if(v == NULL) {
            v = malloc(sizeof(so_Array));
            so_initArray(v, 5);
        }
        return v;
    }
    return v;
}

void _clear_stackoverflow() {
    so_freeArray(v);
    v = NULL;
}

// ALL
double _test_all_stack_overflow(const int obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp;

    start = clock();

    so_Array a;
    so_initArray(&a, 5);

    // add
    for(i = 0; i < n; i++)
        so_insertArray(&a, obj);

    // read
    for(i = 0; i < a.used; i++)
        tmp = a.array[i];

    // write
    for(i = 0; i < a.used; i++)
        a.array[i] = obj;

    so_freeArray(&a);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// INSERT
_TestResult _test_insert_stack_overflow(const int obj, const int n, void *const a) {
    long int i;
    clock_t start, end;

    start = clock();

    // add
    for(i = 0; i < n; i++)
        so_insertArray((so_Array*)a, obj);

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = ((so_Array*)a)->size - ((so_Array*)a)->used;
    return result;
}

// READ
double _test_read_stack_overflow(void *const _a) {
    long int i;
    int tmp;
    clock_t start, end;
    so_Array *a = (so_Array*)_a;

    start = clock();

    // read
    for(i = 0; i < a->used; i++)
        tmp = a->array[i];

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_stack_overflow(const int obj, void *const _a) {
    long int i;
    clock_t start, end;
    so_Array *a = (so_Array*)_a;

    start = clock();

    // write
    for(i = 0; i < a->used; i++)
        a->array[i] = obj;

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}