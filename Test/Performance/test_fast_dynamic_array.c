/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>
#include <stdlib.h>

#include "test.h"
#include "../../FastDynamicArray/FastDynamicArray.h"

static DynamicVector *v = NULL;

void* _get_fast_dynamic_array() {
    if(v == NULL) {
        v = malloc(sizeof(DynamicVector));
        dyvec_init(v);
    }
    return v;
}

void _clear_fast_dynamic_array() {
    dyvec_free(v);
    v = NULL;
}


// ALL
double _test_all_fast_dynamic_array(void *const obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp;

    start = clock();

    DynamicVector vector;
    dyvec_init(&vector);

    // add
    for(i = 0; i < n; i++)
        dyvec_add(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = *(int*)dyvec_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        dyvec_set(&vector, i, obj);

    dyvec_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}


// INSERT
_TestResult _test_insert_fast_dynamic_array(void *const obj, const int n, void *const a) {
    long int i;
    clock_t start, end;

    DynamicVector *vector = (DynamicVector*)a;

    start = clock();

    // add
    for(i = 0; i < n; i++)
        dyvec_add(vector, obj);

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = vector->capacity - vector->size;
    return result;
}

// READ
double _test_read_fast_dynamic_array(const int n, void *const a) {
    long int i;
    int tmp;
    clock_t start, end;

    DynamicVector *vector = (DynamicVector*)a;

    start = clock();

    // read
    for(i = 0; i < n; i++)
        tmp = *(int*)dyvec_get(vector, i);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_fast_dynamic_array(void *const obj, const int n, void *const a) {
    long int i;
    clock_t start, end;

    DynamicVector *vector = (DynamicVector*)a;

    start = clock();

    // write
    for(i = 0; i < n; i++)
        dyvec_set(vector, i, obj);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// DELETE
double _test_delete_fast_dynamic_array(void *const v, const int n) {
    long int i;
    clock_t start, end;

    start = clock();

    // delete
    for(i = 0; i < n; i++)
        dyvec_erase((DynamicVector*)v, 0);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// POP
double _test_pop_fast_dynamic_array(void *const v, const int n) {
    long int i;
    int x;
    clock_t  start, end;

    start = clock();

    // pop
    for(i = 0; i < n; i++)
        x = *(int*)dyvec_pop(v);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}