/*
    Copyright 2018 Simone Martelli

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 *
 * \author Simone Martelli
 * \date 2018-09-08
 * \brief Performance test
*/

#ifndef DYNAMIC_ARRAY_TEST_H
#define DYNAMIC_ARRAY_TEST_H

// flag test
#define _TEST_EDD_MANN 0
#define _TEST_STACK_OVERFLOW 1
#define _TEST_HAPPY_BEAR 2
#define _TEST_MATUGM 3
#define _TEST_STD_ARRAY 4
#define _TEST_FAST_DYNAMIC_ARRAY 5

/**
 * Total number of tests.
 */
#define N_TEST_RIEPILOGO 6

/**
 * Repetitions for each test.
 */
#define _REPEAT 10

/**
 *  Maximum number of elements per test: 50.000.000
 */
#define _MAX 50000000
/**
 *  Maximum number of elements for the test DELETE (it must be lower because the test is slow).
 */
#define _MAX_DELETE 100000

/**
 *  Number of elements per test.
 */
static const unsigned int _N_ITEMS_FOR_TEST[] = {
        1000,
        10000,
        100000,
        1000000,
        25000000,
        50000000
};
/**
 * Number of tests in the order of number of elements.
 */
#define N_TEST (sizeof(_N_ITEMS_FOR_TEST) / sizeof(unsigned int))

/**
 * \struct
 * \brief Result for a specific test
 */
typedef struct {
    unsigned int item; /** Number of elements involved in the test */
    unsigned int unused_space; /** Unused space in the test */
    double time; /** Time taken by the test */
} _TestResult;

/**
 * \struct
 * \brief Summary of the complete test
 */
typedef struct {
    char desc[32]; /** Description of the test */
    _TestResult result[N_TEST]; /** Test results by number of items */
} Summary;

/* test: insert, read and write */
double _test_all_edd_mann(const void*, int);
double _test_all_stack_overflow(int, int);
double _test_all_happy_bear(int, int);
double _test_all_matugm(int, int);
double _test_all_std_array(int, int);
double _test_all_fast_dynamic_array(void*, int);

/* test: insert */
_TestResult _test_insert_edd_mann(const void*, int, void*);
_TestResult _test_insert_stack_overflow(int, int, void*);
_TestResult _test_insert_happy_bear(int, int, void*);
_TestResult _test_insert_matugm(int, int, void*);
_TestResult _test_insert_std_array(int, int, void*);
_TestResult _test_insert_fast_dynamic_array(void*, int, void*);

/* test: read */
double _test_read_edd_mann(const void*);
double _test_read_stack_overflow(void*);
double _test_read_happy_bear(int, void*);
double _test_read_matugm(int, void*);
double _test_read_std_array(int, void*);
double _test_read_fast_dynamic_array(int, void*);

/* test: write */
double _test_write_edd_mann(const void*, void*);
double _test_write_stack_overflow(int, void*);
double _test_write_happy_bear(int, int, void*);
double _test_write_matugm(int, int, void*);
double _test_write_std_array(int, int, void*);
double _test_write_fast_dynamic_array(void*, int, void*);

/* test: delete */
double _test_delete_edd_mann(const void*);
double _test_delete_fast_dynamic_array(void*, int);

/* test: pop & push */
double _test_pop_fast_dynamic_array(void *, int);

void* _get_edd_mann();
void* _get_happy_bear();
void* _get_matugm();
void* _get_stackoverflow();
void* _get_stdarray();
void* _get_fast_dynamic_array();

void _clear_edd_mann();
void _clear_stackoverflow();
void _clear_happy_bear();
void _clear_matugm();
void _clear_fast_dynamic_array();

/**
 * \brief Execute all test: insert, read and write
 * \param[out] test result summary
 *
 * Performs an insert, read and write test on all the algorithms by number of elements.
 */
void execute_test_all(Summary*);
/**
 * \brief Execute all test (insert, read and write) but separately
 * \param[out] test insert summary
 * \param[out] test read summary
 * \param[out] test write summary
 */
void execute_test_parz(Summary*, Summary*, Summary*);
/**
 * \brief Performs the delete tests
 * \param[out] test delete summary
 */
void execute_test_delete(Summary*);
/**
 * \brief Performs the pop tests
 * \param[out] test pop summary
 */
void execute_test_pop(Summary*);

/**
 * \brief Performs test specialization of FastDynamicArray
 * \param[out] test summary
 */
void execute_test_specializations(Summary*);

/**
 *  \brief Print the results of a summary (time)
 *  \param summary
 *  \param description
 */
void print_time(Summary*, char*);
/**
 *  \brief Print the results of a summary (space)
 *  \param summary
 */
void print_space(Summary*);
/**
 *  \brief Init a summary
 *  \param summary
 */
void init(Summary*);

/**
 *
 * \brief Calculates an average of the values ​​in an array
 * \param vector
 * \param number of elements in the vector
 * \return the average of the values
 */
double _media(double *v, int n);
/**
 *
 *  \brief Calculates the information for the summary
 *  \param summary
 *  \param vector of double with time result for each repetition
 *  \param number of elements of the previous vector
 *  \param index of the test result (used to test with different number of elements)
 *  \param number of elements used in the test
 *  \param unused space in the vector
 */
double _calc_summary(Summary*, double*, int, int, int, unsigned int, unsigned int, char*);

/* TEST for INT */
double _test_all_fast_dynamic_array_int(int, int);

#endif //DYNAMIC_ARRAY_TEST_H
