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
#include "../FastDynamicArray/FastDynamicArrayChar.h"
#include "../FastDynamicArray/FastDynamicArrayShortInt.h"
#include "../FastDynamicArray/FastDynamicArrayLong.h"
#include "../FastDynamicArray/FastDynamicArrayLongLong.h"
#include "../FastDynamicArray/FastDynamicArrayFloat.h"
#include "../FastDynamicArray/FastDynamicArrayDouble.h"
#include "../FastDynamicArray/FastDynamicArrayLongDouble.h"

void run_example() {
    // int
    int intX = 10, intY = 20;
    unsigned int unsignedIntX = 25, unsignedIntY = 75;
    signed int signedIntX = -50, signedIntY = -100;
    // char
    char charX = 68, charY = 120;
    unsigned char unsignedCharX = 12, unsignedCharY = 14;
    signed char signedCharX = -10, signedCharY = -16;
    // short int
    short int shortIntX = 128, shortIntY = 256;
    unsigned short int unsignedShortIntX = 512, unsignedShortIntY = 720;
    signed short int signedShortIntX = -128, signedShortIntY = -256;
    // long int
    long int longIntX = 1278, longIntY = 4567;
    signed long int signedLongIntX = -4523, signedLongIntY = -6542;
    unsigned long int unsignedLongIntX = 5542, unsignedLongIntY = 1244;
    // long long int
    long long int longLongIntX = 41435, longLongIntY = 42156;
    signed long long int signedLongLongIntX = -3233, signedLongLongIntY = -52356;
    unsigned long long int unsignedLongLongIntX = 353625, unsignedLongLongIntY = 52933295;
    // float
    float floatX = 10.24, floatY = 15.753;
    // double
    double doubleX = 12.04534, doubleY = 45.8574;
    // long double
    long double longDoubleX = 643.634564, longDoubleY = 534.354235;

    // general purpose
    printf("Example General purpose: \n");
    FDA_INIT(v);
    FDA_ADD(v, &intX);
    printf("Example GET 1: %d\n", *FDA_GET(v, int*, 0));
    FDA_SET(v, 0, &intY);
    printf("Example GET 2: %d\n", *FDA_GET(v, int*, 0));
    FDA_ERASE(v, 0);
    printf("Example size: %lu\n", v.size);
    FDA_ADD(v, &intX);
    printf("Example pop: %d\n", *FDA_POP(v, int*));
    FDA_PUSH(v, &intX);
    printf("Example push: %d\n", *FDA_GET(v, int*, 0));
    FDA_FREE(v);

    // int
    printf("Example INT: \n");
    FDA_INT_INIT(vInt);
    FDA_INT_ADD(vInt, intX);
    printf("Example GET INT 1: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_SET(vInt, 0, intY);
    printf("Example GET INT 2: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_ERASE(vInt, 0);
    printf("Example size: %lu\n", vInt.size);
    FDA_INT_ADD(vInt, intX);
    printf("Example pop: %d\n", FDA_INT_POP(vInt));
    FDA_INT_PUSH(vInt, intX);
    printf("Example push: %d\n", FDA_INT_GET(vInt, 0));
    FDA_INT_FREE(vInt);

    // unsigned int
    printf("Example UINT: \n");
    FDA_UINT_INIT(vUInt);
    FDA_UINT_ADD(vUInt, unsignedIntX);
    printf("Example GET UINT 1: %u\n", FDA_UINT_GET(vUInt, 0));
    FDA_UINT_SET(vUInt, 0, unsignedIntY);
    printf("Example GET UINT 2: %u\n", FDA_UINT_GET(vUInt, 0));
    printf("Example pop: %u\n", FDA_UINT_POP(vUInt));
    FDA_UINT_PUSH(vUInt, unsignedIntX);
    printf("Example push: %u\n", FDA_UINT_GET(vUInt, 0));
    FDA_UINT_FREE(vUInt);

    // signed int
    printf("Example SINT: \n");
    FDA_SINT_INIT(vSInt);
    FDA_SINT_ADD(vSInt, signedIntX);
    printf("Example GET SINT 1: %d\n", FDA_SINT_GET(vSInt, 0));
    FDA_SINT_SET(vSInt, 0, signedIntY);
    printf("Example GET SINT 2: %d\n", FDA_SINT_GET(vSInt, 0));
    printf("Example pop: %d\n", FDA_SINT_POP(vSInt));
    FDA_SINT_PUSH(vSInt, signedIntX);
    printf("Example push: %d\n", FDA_SINT_GET(vSInt, 0));
    FDA_SINT_FREE(vSInt);

    // char
    printf("Example CHAR: \n");
    FDA_CHAR_INIT(vChar);
    FDA_CHAR_ADD(vChar, charX);
    printf("Example GET CHAR 1: %d\n", FDA_CHAR_GET(vChar, 0));
    FDA_CHAR_SET(vChar, 0, charY);
    printf("Example GET CHAR 2: %d\n", FDA_CHAR_GET(vChar, 0));
    printf("Example pop: %d\n", FDA_CHAR_POP(vChar));
    FDA_CHAR_PUSH(vChar, charX);
    printf("Example push: %d\n", FDA_CHAR_GET(vChar, 0));
    FDA_CHAR_FREE(vChar);

    // unsigned char
    printf("Example UCHAR: \n");
    FDA_UCHAR_INIT(vUChar);
    FDA_UCHAR_ADD(vUChar, unsignedCharX);
    printf("Example GET UCHAR 1: %d\n", FDA_UCHAR_GET(vUChar, 0));
    FDA_UCHAR_SET(vUChar, 0, unsignedCharY);
    printf("Example GET UCHAR 2: %d\n", FDA_UCHAR_GET(vUChar, 0));
    printf("Example pop: %d\n", FDA_UCHAR_POP(vUChar));
    FDA_UCHAR_PUSH(vUChar, unsignedCharX);
    printf("Example push: %d\n", FDA_UCHAR_GET(vUChar, 0));
    FDA_UCHAR_FREE(vUChar);

    // signed char
    printf("Example SCHAR: \n");
    FDA_SCHAR_INIT(vSChar);
    FDA_SCHAR_ADD(vSChar, signedCharX);
    printf("Example GET SCHAR 1: %d\n", FDA_SCHAR_GET(vSChar, 0));
    FDA_SCHAR_SET(vSChar, 0, signedCharY);
    printf("Example GET SCHAR 2: %d\n", FDA_SCHAR_GET(vSChar, 0));
    printf("Example pop: %d\n", FDA_SCHAR_POP(vSChar));
    FDA_SCHAR_PUSH(vSChar, signedCharX);
    printf("Example push: %d\n", FDA_SCHAR_GET(vSChar, 0));
    FDA_SCHAR_FREE(vSChar);

    // short int
    printf("Example SHORT INT: \n");
    FDA_SHORTINT_INIT(vShortInt);
    FDA_SHORTINT_ADD(vShortInt, shortIntX);
    printf("Example GET SHORT INT 1: %hi\n", FDA_SHORTINT_GET(vShortInt, 0));
    FDA_SHORTINT_SET(vShortInt, 0, shortIntY);
    printf("Example GET SHORT INT 2: %hi\n", FDA_SHORTINT_GET(vShortInt, 0));
    FDA_SHORTINT_ERASE(vShortInt, 0);
    printf("Example size: %lu\n", vShortInt.size);
    FDA_SHORTINT_ADD(vShortInt, shortIntX);
    printf("Example pop: %hi\n", FDA_SHORTINT_POP(vShortInt));
    FDA_SHORTINT_PUSH(vShortInt, shortIntX);
    printf("Example push: %hi\n", FDA_SHORTINT_GET(vShortInt, 0));
    FDA_SHORTINT_FREE(vShortInt);

    // signed short int
    printf("Example SIGNED SHORT INT: \n");
    FDA_SHORTSINT_INIT(vShortSInt);
    FDA_SHORTSINT_ADD(vShortSInt, signedShortIntX);
    printf("Example GET SIGNED SHORT INT 1: %hi\n", FDA_SHORTSINT_GET(vShortSInt, 0));
    FDA_SHORTSINT_SET(vShortSInt, 0, signedShortIntY);
    printf("Example GET SIGNED SHORT INT 2: %hi\n", FDA_SHORTSINT_GET(vShortSInt, 0));
    printf("Example pop: %hi\n", FDA_SHORTSINT_POP(vShortSInt));
    FDA_SHORTSINT_PUSH(vShortSInt, signedShortIntX);
    printf("Example push: %hi\n", FDA_SHORTSINT_GET(vShortSInt, 0));
    FDA_SHORTSINT_FREE(vShortSInt);

    // unsigned short int
    printf("Example UNSIGNED SHORT INT: \n");
    FDA_SHORTUINT_INIT(vShortUInt);
    FDA_SHORTUINT_ADD(vShortUInt, unsignedShortIntX);
    printf("Example GET UNSIGNED SHORT INT 1: %hu\n", FDA_SHORTUINT_GET(vShortUInt, 0));
    FDA_SHORTUINT_SET(vShortUInt, 0, unsignedShortIntY);
    printf("Example GET UNSIGNED SHORT INT 2: %hu\n", FDA_SHORTUINT_GET(vShortUInt, 0));
    printf("Example pop: %hu\n", FDA_SHORTUINT_POP(vShortUInt));
    FDA_SHORTUINT_PUSH(vShortUInt, unsignedShortIntX);
    printf("Example push: %hu\n", FDA_SHORTUINT_GET(vShortUInt, 0));
    FDA_SHORTUINT_FREE(vShortUInt);

    // long int
    printf("Example LONG INT: \n");
    FDA_LONG_INIT(vLongInt);
    FDA_LONG_ADD(vLongInt, longIntX);
    printf("Example GET LONG INT 1: %li\n", FDA_LONG_GET(vLongInt, 0));
    FDA_LONG_SET(vLongInt, 0, longIntY);
    printf("Example GET LONG INT 2: %li\n", FDA_LONG_GET(vLongInt, 0));
    FDA_LONG_ERASE(vLongInt, 0);
    printf("Example size: %lu\n", vLongInt.size);
    FDA_LONG_ADD(vLongInt, longIntX);
    printf("Example pop: %li\n", FDA_LONG_POP(vLongInt));
    FDA_LONG_PUSH(vLongInt, longIntX);
    printf("Example push: %li\n", FDA_LONG_GET(vLongInt, 0));
    FDA_LONG_FREE(vLongInt);

    // signed long int
    printf("Example SIGNED LONG INT: \n");
    FDA_SLONG_INIT(vLongSInt);
    FDA_SLONG_ADD(vLongSInt, signedLongIntX);
    printf("Example GET SIGNED LONG INT 1: %li\n", FDA_SLONG_GET(vLongSInt, 0));
    FDA_SLONG_SET(vLongSInt, 0, signedLongIntY);
    printf("Example GET SIGNED LONG INT 2: %li\n", FDA_SLONG_GET(vLongSInt, 0));
    printf("Example pop: %li\n", FDA_SLONG_POP(vLongSInt));
    FDA_SLONG_PUSH(vLongSInt, signedLongIntX);
    printf("Example push: %li\n", FDA_SLONG_GET(vLongSInt, 0));
    FDA_SLONG_FREE(vLongSInt);

    // unsigned long int
    printf("Example UNSIGNED LONG INT: \n");
    FDA_ULONG_INIT(vLongUInt);
    FDA_ULONG_ADD(vLongUInt, unsignedLongIntX);
    printf("Example GET UNSIGNED LONG INT 1: %lu\n", FDA_ULONG_GET(vLongUInt, 0));
    FDA_ULONG_SET(vLongUInt, 0, unsignedLongIntY);
    printf("Example GET UNSIGNED LONG INT 2: %lu\n", FDA_ULONG_GET(vLongUInt, 0));
    printf("Example pop: %lu\n", FDA_ULONG_POP(vLongUInt));
    FDA_ULONG_PUSH(vLongUInt, unsignedLongIntX);
    printf("Example push: %lu\n", FDA_ULONG_GET(vLongUInt, 0));
    FDA_ULONG_FREE(vLongUInt);

    // long long int
    printf("Example LONG LONG INT: \n");
    FDA_LONGLONG_INIT(vLongLongInt);
    FDA_LONGLONG_ADD(vLongLongInt, longLongIntX);
    printf("Example GET LONG LONG INT 1: %lli\n", FDA_LONGLONG_GET(vLongLongInt, 0));
    FDA_LONGLONG_SET(vLongLongInt, 0, longLongIntY);
    printf("Example GET LONG LONG INT 2: %lli\n", FDA_LONGLONG_GET(vLongLongInt, 0));
    FDA_LONGLONG_ERASE(vLongLongInt, 0);
    printf("Example size: %lu\n", vLongLongInt.size);
    FDA_LONGLONG_ADD(vLongLongInt, longLongIntX);
    printf("Example pop: %lli\n", FDA_LONGLONG_POP(vLongLongInt));
    FDA_LONGLONG_PUSH(vLongLongInt, longLongIntX);
    printf("Example push: %lli\n", FDA_LONGLONG_GET(vLongLongInt, 0));
    FDA_LONGLONG_FREE(vLongLongInt);

    // signed long long int
    printf("Example SIGNED LONG LONG INT: \n");
    FDA_SLONGLONG_INIT(vLongLongSInt);
    FDA_SLONGLONG_ADD(vLongLongSInt, signedLongLongIntX);
    printf("Example GET SIGNED LONG LONG INT 1: %lli\n", FDA_SLONGLONG_GET(vLongLongSInt, 0));
    FDA_SLONGLONG_SET(vLongLongSInt, 0, signedLongLongIntY);
    printf("Example GET SIGNED LONG LONG INT 2: %lli\n", FDA_SLONGLONG_GET(vLongLongSInt, 0));
    printf("Example pop: %lli\n", FDA_SLONGLONG_POP(vLongLongSInt));
    FDA_SLONGLONG_PUSH(vLongLongSInt, signedLongLongIntX);
    printf("Example push: %lli\n", FDA_SLONGLONG_GET(vLongLongSInt, 0));
    FDA_SLONGLONG_FREE(vLongLongSInt);

    // unsigned long int
    printf("Example UNSIGNED LONG LONG INT: \n");
    FDA_ULONGLONG_INIT(vLongLongUInt);
    FDA_ULONGLONG_ADD(vLongLongUInt, unsignedLongLongIntX);
    printf("Example GET UNSIGNED LONG LONG INT 1: %llu\n", FDA_ULONGLONG_GET(vLongLongUInt, 0));
    FDA_ULONGLONG_SET(vLongLongUInt, 0, unsignedLongLongIntY);
    printf("Example GET UNSIGNED LONG LONG INT 2: %llu\n", FDA_ULONGLONG_GET(vLongLongUInt, 0));
    printf("Example pop: %llu\n", FDA_ULONGLONG_POP(vLongLongUInt));
    FDA_ULONGLONG_PUSH(vLongLongUInt, unsignedLongLongIntX);
    printf("Example push: %llu\n", FDA_ULONGLONG_GET(vLongLongUInt, 0));
    FDA_ULONGLONG_FREE(vLongLongUInt);

    // float
    printf("Example FLOAT: \n");
    FDA_FLOAT_INIT(vFloatInt);
    FDA_FLOAT_ADD(vFloatInt, floatX);
    printf("Example GET FLOAT 1: %f\n", FDA_FLOAT_GET(vFloatInt, 0));
    FDA_FLOAT_SET(vFloatInt, 0, floatY);
    printf("Example GET FLOAT 2: %f\n", FDA_FLOAT_GET(vFloatInt, 0));
    FDA_FLOAT_ERASE(vFloatInt, 0);
    printf("Example size: %lu\n", vFloatInt.size);
    FDA_FLOAT_ADD(vFloatInt, floatX);
    printf("Example pop: %f\n", FDA_FLOAT_POP(vFloatInt));
    FDA_FLOAT_PUSH(vFloatInt, floatX);
    printf("Example push: %f\n", FDA_FLOAT_GET(vFloatInt, 0));
    FDA_FLOAT_FREE(vFloatInt);

    // double
    printf("Example DOUBLE: \n");
    FDA_DOUBLE_INIT(vDoubleInt);
    FDA_DOUBLE_ADD(vDoubleInt, doubleX);
    printf("Example GET DOUBLE 1: %lf\n", FDA_DOUBLE_GET(vDoubleInt, 0));
    FDA_DOUBLE_SET(vDoubleInt, 0, doubleY);
    printf("Example GET DOUBLE 2: %lf\n", FDA_DOUBLE_GET(vDoubleInt, 0));
    FDA_DOUBLE_ERASE(vDoubleInt, 0);
    printf("Example size: %lu\n", vDoubleInt.size);
    FDA_DOUBLE_ADD(vDoubleInt, doubleX);
    printf("Example pop: %lf\n", FDA_DOUBLE_POP(vDoubleInt));
    FDA_DOUBLE_PUSH(vDoubleInt, doubleX);
    printf("Example push: %lf\n", FDA_DOUBLE_GET(vDoubleInt, 0));
    FDA_DOUBLE_FREE(vDoubleInt);

    // long double
    printf("Example LONG DOUBLE: \n");
    FDA_LONGDOUBLE_INIT(vLongDoubleInt);
    FDA_LONGDOUBLE_ADD(vLongDoubleInt, longDoubleX);
    printf("Example GET LONG DOUBLE 1: %Lg\n", FDA_LONGDOUBLE_GET(vLongDoubleInt, 0));
    FDA_LONGDOUBLE_SET(vLongDoubleInt, 0, longDoubleY);
    printf("Example GET LONG DOUBLE 2: %Lg\n", FDA_LONGDOUBLE_GET(vLongDoubleInt, 0));
    FDA_LONGDOUBLE_ERASE(vLongDoubleInt, 0);
    printf("Example size: %lu\n", vLongDoubleInt.size);
    FDA_LONGDOUBLE_ADD(vLongDoubleInt, longDoubleX);
    printf("Example pop: %Lg\n", FDA_LONGDOUBLE_POP(vLongDoubleInt));
    FDA_LONGDOUBLE_PUSH(vLongDoubleInt, longDoubleX);
    printf("Example push: %Lg\n", FDA_LONGDOUBLE_GET(vLongDoubleInt, 0));
    FDA_LONGDOUBLE_FREE(vLongDoubleInt);
}

#endif //DYNAMIC_ARRAY_EXAMPLE_H
