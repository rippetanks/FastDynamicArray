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

#define RUN_UNIT_TEST
#define RUN_PERFORMANCE_TEST

int main(int argc, char *argv[]) {
    Summary summaryAll[N_TEST_RIEPILOGO];
    Summary summaryInsert[N_TEST_RIEPILOGO];
    Summary summaryRead[N_TEST_RIEPILOGO];
    Summary summaryWrite[N_TEST_RIEPILOGO];
    Summary summaryDelete[N_TEST_RIEPILOGO];
    Summary summaryPop[N_TEST_RIEPILOGO];

    // unit test
#ifdef RUN_UNIT_TEST
    UNITY_BEGIN();

    RUN_TEST(utest_init);
    RUN_TEST(utest_insert_read_write);
    RUN_TEST(utest_insert_resize);
    RUN_TEST(utest_erase);
    RUN_TEST(utest_erase_interval);
    RUN_TEST(utest_push_pop);
    RUN_TEST(utest_free);

    UNITY_END();
#endif

    // performance test
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

    print_time(summaryAll, "ALL");
    print_time(summaryInsert, "INSERT");
    print_time(summaryRead, "READ");
    print_time(summaryWrite, "WRITE");
    print_space(summaryInsert);
    print_time(summaryDelete, "DELETE");
    print_time(summaryDelete, "POP");
#endif

    return 0;
}