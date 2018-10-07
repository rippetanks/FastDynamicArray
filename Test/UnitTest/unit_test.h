/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 *
 * \author S. Martelli
 * \date 2018-09-14
 */

#ifndef DYNAMIC_ARRAY_UNIT_TEST_H
#define DYNAMIC_ARRAY_UNIT_TEST_H

/**
 * Number of elements used for the tests
 */
#define _UNIT_TEST_N 5000

/**
 * \brief Init test
 */
void utest_init();
/**
 * \brief Test insert, read and write functions
 */
void utest_insert_read_write();
/**
 * \brief Test insert and resize functions
 */
void utest_insert_resize();
/**
 * \brief Test erase functions
 */
void utest_erase();
/**
 * \brief Test erase interval functions
 */
void utest_erase_interval();
/**
 * \brief Test push and pop functions
 */
void utest_push_pop();
/**
 * \brief Test free functions
 */
void utest_free();

/* INT unit test */
void utest_int_init();
void utest_int_insert_read_write();
void utest_int_insert_resize();
void utest_int_erase();
void utest_int_erase_interval();
void utest_int_push_pop();
void utest_int_free();

#endif //DYNAMIC_ARRAY_UNIT_TEST_H
