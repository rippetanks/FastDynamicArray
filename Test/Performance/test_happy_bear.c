/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>
#include <stdlib.h>

#include "test.h"
#include "../../Other/HappyBear/HappyBear.h"

static hb_Vector *v = NULL;

void* _get_happy_bear() {
    if(v == NULL) {
        v = malloc(sizeof(hb_Vector));
        hb_vector_init(v);
    }
    return v;
}

void _clear_happy_bear() {
    hb_vector_free(v);
    v = NULL;
}

// ALL
double _test_all_happy_bear(const int obj, const int n) {
    long int i;
    clock_t start, end;
    int tmp = 0;

    start = clock();
    hb_Vector vector;
    hb_vector_init(&vector);

    // add
    for(i = 0; i < n; i++)
        hb_vector_append(&vector, obj);

    // read
    for(i = 0; i < n; i++)
        tmp = hb_vector_get(&vector, i);

    // write
    for(i = 0; i < n; i++)
        hb_vector_set(&vector, i, tmp);

    hb_vector_free(&vector);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// INSERT
_TestResult _test_insert_happy_bear(const int obj, const int n, void *const v) {
    long int i;
    clock_t start, end;

    start = clock();

    // add
    for(i = 0; i < n; i++)
        hb_vector_append((hb_Vector*)v, obj);

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = ((hb_Vector*)v)->capacity - ((hb_Vector*)v)->size;
    return result;
}

// READ
double _test_read_happy_bear(const int n, void *const v) {
    long int i;
    int tmp;
    clock_t start, end;

    start = clock();

    // read
    for(i = 0; i < n; i++)
        tmp = hb_vector_get((hb_Vector*)v, i);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_happy_bear(const int obj, const int n, void *const v) {
    long int i;
    clock_t start, end;

    start = clock();

    // write
    for(i = 0; i < n; i++)
        hb_vector_set((hb_Vector*)v, i, obj);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

