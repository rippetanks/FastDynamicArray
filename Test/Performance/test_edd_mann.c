/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <time.h>
#include <stdlib.h>

#include "test.h"
#include "../../Other/EddMann/EddMann.h"

static ed_vector *v = NULL;

void* _get_edd_mann() {
    if(v == NULL) {
        v = malloc(sizeof(ed_vector));
        ed_vector_init(v);
    }
    return v;
}

void _clear_edd_mann() {
    ed_vector_free(v);
    v = NULL;
}

// ALL
double _test_all_edd_mann(const void *const obj, const int n) {
    unsigned int i;
    void *tmp = NULL;
    clock_t start, end;

    start = clock();

    VECTOR_INIT(v);

    // add
    for(i = 0; i < n; i++)
        VECTOR_ADD(v, obj);

    // read
    for (i = 0; i < VECTOR_TOTAL(v); i++)
        tmp = VECTOR_GET(v, void*, i);

    // write
    for(i = 0; i < VECTOR_TOTAL(v); i++)
        VECTOR_SET(v, i, tmp);

    VECTOR_FREE(v);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// INSERT
_TestResult _test_insert_edd_mann(const void *const obj, const int n, void *const v) {
    unsigned int i;
    clock_t start, end;

    start = clock();

    // add
    for(i = 0; i < n; i++)
        VECTOR_ADD(*(ed_vector*)v, obj);

    end = clock();
    _TestResult result;
    result.time = ((double) (end - start)) / CLOCKS_PER_SEC;
    result.unused_space = ((ed_vector*)v)->capacity - ((ed_vector*)v)->total;
    return result;
}

// READ
double _test_read_edd_mann(const void *const v) {
    unsigned int i;
    void *tmp;
    clock_t start, end;

    start = clock();

    // read
    for (i = 0; i < VECTOR_TOTAL(*(ed_vector*)v); i++)
        tmp = VECTOR_GET(*(ed_vector*)v, void*, i);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// WRITE
double _test_write_edd_mann(const void *const obj, void *const v) {
    unsigned int i;
    clock_t start, end;

    start = clock();

    // write
    for(i = 0; i < VECTOR_TOTAL(*(ed_vector*)v); i++)
        VECTOR_SET(*(ed_vector*)v, i, obj);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// DELETE
double _test_delete_edd_mann(const void *const v) {
    unsigned int i;
    clock_t  start, end;

    start = clock();

    for(i = 0; i < VECTOR_TOTAL(*(ed_vector*)v); i++)
        VECTOR_DELETE(*(ed_vector*)v, 0);

    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}