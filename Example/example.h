/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef DYNAMIC_ARRAY_EXAMPLE_H
#define DYNAMIC_ARRAY_EXAMPLE_H

#include <stdio.h>

#include "../FastDynamicArray/FastDynamicArray.h"
#include "../FastDynamicArray/FastDynamicArrayInt.h"

void run_example() {
    int x = 10, y = 20;
    unsigned int ux = 25, uy = 75;
    signed int sx = 50, sy = 100;

    // general purpose
    printf("Example General purpose: \n");
    FDA_INIT(v);
    FDA_ADD(v, &x);
    printf("Example GET 1: %d\n", *FDA_GET(v, int*, 0));
    FDA_SET(v, 0, &y);
    printf("Example GET 2: %d\n", *FDA_GET(v, int*, 0));
    FDA_ERASE(v, 0);
    printf("Example size: %lu\n", v.size);
    FDA_ADD(v, &x);
    printf("Example pop: %d\n", *FDA_POP(v, int*));
    FDA_PUSH(v, &x);
    printf("Example push: %d\n", *FDA_GET(v, int*, 0));
    FDA_FREE(v);

    // int
    printf("Example INT: \n");
    FDA_INT_INIT(vInt);
    FDA_INT_ADD(vInt, x);
    printf("Example GET INT 1: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_SET(vInt, 0, y);
    printf("Example GET INT 2: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_ERASE(vInt, 0);
    printf("Example size: %lu\n", vInt.size);
    FDA_INT_ADD(vInt, x);
    printf("Example pop: %d\n", FDA_INT_POP(vInt));
    FDA_INT_PUSH(vInt, x);
    printf("Example push: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_FREE(vInt);

    // unsigned int
    printf("Example UINT: \n");
    FDA_UINT_INIT(vUInt);
    FDA_UINT_ADD(vUInt, ux);
    printf("Example GET UINT 1: %d\n", FDA_UINT_GET(vUInt, 0));
    FDA_UINT_SET(vUInt, 0, uy);
    printf("Example GET UINT 2: %d\n", FDA_UINT_GET(vUInt, 0));
    printf("Example pop: %d\n", FDA_UINT_POP(vUInt));
    FDA_UINT_PUSH(vUInt, ux);
    printf("Example push: %d\n", FDA_UINT_GET(vUInt, 0));
    FDA_UINT_FREE(vUInt);

    // signed int
    printf("Example SINT: \n");
    FDA_SINT_INIT(vSInt);
    FDA_SINT_ADD(vSInt, sx);
    printf("Example GET SINT 1: %d\n", FDA_SINT_GET(vSInt, 0));
    FDA_SINT_SET(vSInt, 0, sy);
    printf("Example GET SINT 2: %d\n", FDA_SINT_GET(vSInt, 0));
    printf("Example pop: %d\n", FDA_SINT_POP(vSInt));
    FDA_SINT_PUSH(vSInt, sx);
    printf("Example push: %d\n", FDA_SINT_GET(vSInt, 0));
    FDA_SINT_FREE(vSInt);
}

#endif //DYNAMIC_ARRAY_EXAMPLE_H
