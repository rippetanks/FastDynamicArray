cmake_minimum_required(VERSION 3.9)
project(dynamic_array C)

set(CMAKE_C_STANDARD 99)

# STACK SPACE FOR STD ARRAY TEST
MATH(EXPR stack_size "192 * 1024 * 1024") # 192 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(
        dynamic_array
        main.c
        EddMann/EddMann.h EddMann/EddMann.c
        StackOverflow/StackOverflow.h
        HappyBear/HappyBear.h HappyBear/HappyBear.c
        Matugm/Matugm.h Matugm/Matugm.c
        FastDynamicArray/FastDynamicArray.h FastDynamicArray/FastDynamicArray.c
        Test/Performance/test.h Test/Performance/test.c
        Test/Performance/test_edd_mann.c
        Test/Performance/test_stack_overflow.c
        Test/Performance/test_happy_bear.c
        Test/Performance/test_matugm.c
        Test/Performance/test_fast_dynamic_array.c
        Test/Performance/test_std_array.c
        Test/UnitTest/unity.h Test/UnitTest/unity_internals.h Test/UnitTest/unity.c
        Test/UnitTest/unit_test.h Test/UnitTest/unit_test.c)