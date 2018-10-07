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
