/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <stdio.h>

#include "Test/Performance/test.h"
#include "Test/UnitTest/unity.h"
#include "Test/UnitTest/unit_test.h"

#include "Example/example.h"

#define RUN_UNIT_TEST
#define RUN_PERFORMANCE_TEST
#define RUN_EXAMPLE

int main(int argc, char *argv[]) {
    Summary summaryAll[N_TEST_RIEPILOGO];
    Summary summaryInsert[N_TEST_RIEPILOGO];
    Summary summaryRead[N_TEST_RIEPILOGO];
    Summary summaryWrite[N_TEST_RIEPILOGO];
    Summary summaryDelete[N_TEST_RIEPILOGO];
    Summary summaryPop[N_TEST_RIEPILOGO];
    Summary summarySpecialization[8];

    // unit test
#ifdef RUN_UNIT_TEST
    UNITY_BEGIN();

    // general purpose
    RUN_TEST(utest_init);
    RUN_TEST(utest_insert_read_write);
    RUN_TEST(utest_insert_resize);
    RUN_TEST(utest_erase);
    RUN_TEST(utest_erase_interval);
    RUN_TEST(utest_push_pop);
    RUN_TEST(utest_free);

    // int
    RUN_TEST(utest_int_init);
    RUN_TEST(utest_int_insert_read_write);
    RUN_TEST(utest_int_insert_resize);
    RUN_TEST(utest_int_erase);
    RUN_TEST(utest_int_erase_interval);
    RUN_TEST(utest_int_push_pop);
    RUN_TEST(utest_int_free);

    // char
    RUN_TEST(utest_char_init);
    RUN_TEST(utest_char_insert_read_write);
    RUN_TEST(utest_char_insert_resize);
    RUN_TEST(utest_char_erase);
    RUN_TEST(utest_char_erase_interval);
    RUN_TEST(utest_char_push_pop);
    RUN_TEST(utest_char_free);

    // short int
    RUN_TEST(utest_sint_init);
    RUN_TEST(utest_sint_insert_read_write);
    RUN_TEST(utest_sint_insert_resize);
    RUN_TEST(utest_sint_erase);
    RUN_TEST(utest_sint_erase_interval);
    RUN_TEST(utest_sint_push_pop);
    RUN_TEST(utest_sint_free);

    // long int
    RUN_TEST(utest_long_init);
    RUN_TEST(utest_long_insert_read_write);
    RUN_TEST(utest_long_insert_resize);
    RUN_TEST(utest_long_erase);
    RUN_TEST(utest_long_erase_interval);
    RUN_TEST(utest_long_push_pop);
    RUN_TEST(utest_long_free);

    // long long int
    RUN_TEST(utest_longlong_init);
    RUN_TEST(utest_longlong_insert_read_write);
    RUN_TEST(utest_longlong_insert_resize);
    RUN_TEST(utest_longlong_erase);
    RUN_TEST(utest_longlong_erase_interval);
    RUN_TEST(utest_longlong_push_pop);
    RUN_TEST(utest_longlong_free);

    // float
    RUN_TEST(utest_float_init);
    RUN_TEST(utest_float_insert_read_write);
    RUN_TEST(utest_float_insert_resize);
    RUN_TEST(utest_float_erase);
    RUN_TEST(utest_float_erase_interval);
    RUN_TEST(utest_float_push_pop);
    RUN_TEST(utest_float_free);

    // double
    RUN_TEST(utest_double_init);
    RUN_TEST(utest_double_insert_read_write);
    RUN_TEST(utest_double_insert_resize);
    RUN_TEST(utest_double_erase);
    RUN_TEST(utest_double_erase_interval);
    RUN_TEST(utest_double_push_pop);
    RUN_TEST(utest_double_free);

    // float
    RUN_TEST(utest_longdouble_init);
    RUN_TEST(utest_longdouble_insert_read_write);
    RUN_TEST(utest_longdouble_insert_resize);
    RUN_TEST(utest_longdouble_erase);
    RUN_TEST(utest_longdouble_erase_interval);
    RUN_TEST(utest_longdouble_push_pop);
    RUN_TEST(utest_longdouble_free);

    UNITY_END();
#endif

    // performance test on general purpose
#ifdef RUN_PERFORMANCE_TEST
    init(summaryAll);
    init(summaryInsert);
    init(summaryRead);
    init(summaryWrite);
    init(summaryPop);

    execute_test_all(summaryAll);
    execute_test_parz(summaryInsert, summaryRead, summaryWrite);
    execute_test_delete(summaryDelete);
    execute_test_pop(summaryPop);

    print_time(summaryAll, "ALL", N_TEST_RIEPILOGO);
    print_time(summaryInsert, "INSERT", N_TEST_RIEPILOGO);
    print_time(summaryRead, "READ", N_TEST_RIEPILOGO);
    print_time(summaryWrite, "WRITE", N_TEST_RIEPILOGO);
    print_space(summaryInsert);
    print_time(summaryDelete, "DELETE", N_TEST_RIEPILOGO);
    print_time(summaryDelete, "POP", N_TEST_RIEPILOGO);

    // specializations
    init(summarySpecialization);
    execute_test_specializations(summarySpecialization);
    print_time(summarySpecialization, "ALL SPECIALIZATIONS", 8);
#endif

#ifdef RUN_EXAMPLE
    run_example();
#endif

    return 0;
}