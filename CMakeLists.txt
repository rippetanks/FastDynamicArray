cmake_minimum_required(VERSION 3.9)
project(dynamic_array C)

# https://cmake.org/cmake/help/v3.1/prop_tgt/C_STANDARD.html
set(CMAKE_C_STANDARD 99)

# STACK SPACE FOR STD ARRAY TEST
MATH(EXPR stack_size "192 * 1024 * 1024") # 192 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(
        dynamic_array
        main.c
        Other/EddMann/EddMann.h Other/EddMann/EddMann.c
        Other/StackOverflow/StackOverflow.h
        Other/HappyBear/HappyBear.h Other/HappyBear/HappyBear.c
        Other/Matugm/Matugm.h Other/Matugm/Matugm.c
        FastDynamicArray/FastDynamicArray.h FastDynamicArray/FastDynamicArray.c
        FastDynamicArray/FastDynamicArrayInt.h FastDynamicArray/FastDynamicArrayInt.c
        FastDynamicArray/FastDynamicArrayChar.h FastDynamicArray/FastDynamicArrayChar.c
        FastDynamicArray/FastDynamicArrayShortInt.h FastDynamicArray/FastDynamicArrayShortInt.c
        FastDynamicArray/FastDynamicArrayLong.h FastDynamicArray/FastDynamicArrayLong.c
        FastDynamicArray/FastDynamicArrayLongLong.h FastDynamicArray/FastDynamicArrayLongLong.c
        FastDynamicArray/FastDynamicArrayFloat.h FastDynamicArray/FastDynamicArrayFloat.c
        FastDynamicArray/FastDynamicArrayDouble.h FastDynamicArray/FastDynamicArrayDouble.c
        FastDynamicArray/FastDynamicArrayLongDouble.h FastDynamicArray/FastDynamicArrayLongDouble.c
        Test/Performance/test.h Test/Performance/test.c
        Test/Performance/test_edd_mann.c
        Test/Performance/test_stack_overflow.c
        Test/Performance/test_happy_bear.c
        Test/Performance/test_matugm.c
        Test/Performance/test_fast_dynamic_array.c
        Test/Performance/test_fast_dynamic_array_specializations.c
        Test/Performance/test_std_array.c
        Test/UnitTest/unity.h Test/UnitTest/unity_internals.h Test/UnitTest/unity.c
        Test/UnitTest/unit_test.h Test/UnitTest/unit_test.c
        Test/UnitTest/unit_test_int.c
        Test/UnitTest/unit_test_char.c
        Test/UnitTest/unit_test_shortint.c
        Example/example.h Test/UnitTest/unit_test_long.c Test/UnitTest/unit_test_longlong.c Test/UnitTest/unit_test_float.c Test/UnitTest/unit_test_double.c Test/UnitTest/unit_test_longdouble.c)