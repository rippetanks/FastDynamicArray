
#include <stdio.h>
#include <string.h>

#include "test.h"

void execute_test_all(Summary *riepilogo) {
    double time;
    int i, j, progTest;
    unsigned int nItem;
    double result[_REPEAT];
    // obj is a random value
    int obj = 128;

    progTest = 0;
    printf("Execute TEST ALL! Repeat for each test: %d\n", _REPEAT);
    for(j = 0; j < N_TEST; j++) {
        // execute test on nItem elements
        nItem = _N_ITEMS_FOR_TEST[j];
        progTest = 0;
        printf("Execute test on %d item... \n", nItem);

        /*
         * Repeat the test for _REPEAT times, calculates a mean and stores the result into "riepilogo"
         */
#ifdef _TEST_EDD_MANN
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_edd_mann(&obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "Edd Mann");
        printf("Edd Mann - RESULT: %.3fs\n", time);
        progTest++;
#endif
#ifdef _TEST_STACK_OVERFLOW
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_stack_overflow(obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "StackOverflow");
        printf("StackOverflow - RESULT: %.3fs\n", time);
        progTest++;
#endif
#ifdef  _TEST_HAPPY_BEAR
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_happy_bear(obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "HappyBear");
        printf("HappyBear - RESULT: %fs\n", time);
        progTest++;
#endif
#ifdef _TEST_MATUGM
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_matugm(obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "Matugm");
        printf("Matugm - RESULT: %fs\n", time);
        progTest++;
#endif
#ifdef _TEST_STD_ARRAY
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_std_array(obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "Std Array");
        printf("Std Array - RESULT: %fs\n", time);
        progTest++;
#endif
#ifdef _TEST_FAST_DYNAMIC_ARRAY
        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array(&obj, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FastDynamic");
        printf("FastDynamic - RESULT: %fs\n", time);
        progTest++;
#endif
        printf("Done\n");
        fflush(stdout);
    }

    if(progTest < N_TEST_RIEPILOGO)
        riepilogo[progTest].desc[0] = 0;
}


void execute_test_parz(Summary *rInsert, Summary *rRead, Summary *rWrite) {
    double time;
    int i, j, progTest;
    unsigned int nItem;
    double resultIns[_REPEAT], resultRead[_REPEAT], resultWrite[_REPEAT];
    _TestResult r;
    void *v;
    int obj = 128; // random value

    progTest = 0;
    printf("Execute TEST PARZ! Repeat for each test: %d\n", _REPEAT);
    for(j = 0; j < N_TEST; j++) {

        nItem = _N_ITEMS_FOR_TEST[j];
        progTest = 0;
        printf("Execute test on %d item... \n", nItem);

#ifdef _TEST_EDD_MANN
        for (i = 0; i < _REPEAT; i++) {
            v = _get_edd_mann();
            r = _test_insert_edd_mann(&obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_edd_mann(v);
            resultWrite[i] = _test_write_edd_mann(&obj, v);
            _clear_edd_mann();
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "Edd Mann");
        printf("Edd Mann - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "Edd Mann");
        printf("Edd Mann - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "Edd Mann");
        printf("Edd Mann - write parz: %.3fs\n", time);

        progTest++;
#endif
#ifdef _TEST_STACK_OVERFLOW
        for (i = 0; i < _REPEAT; i++) {
            v = _get_stackoverflow();
            r = _test_insert_stack_overflow(obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_stack_overflow(v);
            resultWrite[i] = _test_write_stack_overflow(obj, v);
            _clear_stackoverflow();
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "StackOverflow");
        printf("StackOverflow - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "StackOverflow");
        printf("StackOverflow - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "StackOverflow");
        printf("StackOverflow - write parz: %.3fs\n", time);

        progTest++;
#endif
#ifdef  _TEST_HAPPY_BEAR
        for (i = 0; i < _REPEAT; i++) {
            v = _get_happy_bear();
            r = _test_insert_happy_bear(obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_happy_bear(nItem, v);
            resultWrite[i] = _test_write_happy_bear(obj, nItem, v);
            _clear_happy_bear();
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "HappyBear");
        printf("HappyBear - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "HappyBear");
        printf("HappyBear - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "HappyBear");
        printf("HappyBear - write parz: %.3fs\n", time);

        progTest++;
#endif
#ifdef _TEST_MATUGM
        for (i = 0; i < _REPEAT; i++) {
            v = _get_matugm();
            r = _test_insert_matugm(obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_matugm(nItem, v);
            resultWrite[i] = _test_write_matugm(obj, nItem, v);
            _clear_matugm();
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "Matugm");
        printf("Matugm - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "Matugm");
        printf("Matugm - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "Matugm");
        printf("Matugm - write parz: %.3fs\n", time);

        progTest++;
#endif
#ifdef _TEST_STD_ARRAY
        for (i = 0; i < _REPEAT; i++) {
            v = _get_stdarray();
            r = _test_insert_std_array(obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_std_array(nItem, v);
            resultWrite[i] = _test_write_std_array(obj, nItem, v);
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "Std Array");
        printf("Std Array - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "Std Array");
        printf("Std Array - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "Std Array");
        printf("Std Array - write parz: %.3fs\n", time);

        progTest++;
#endif
#ifdef _TEST_FAST_DYNAMIC_ARRAY
        for (i = 0; i < _REPEAT; i++) {
            v = _get_fast_dynamic_array();
            r = _test_insert_fast_dynamic_array(&obj, nItem, v);
            resultIns[i] = r.time;
            resultRead[i] = _test_read_fast_dynamic_array(nItem, v);
            resultWrite[i] = _test_write_fast_dynamic_array(&obj, nItem, v);
            _clear_fast_dynamic_array();
        }
        // insert
        time = _calc_summary(rInsert, resultIns, _REPEAT, progTest, j, nItem, r.unused_space, "FastDynamic");
        printf("FastDynamic - ins parz: %.3fs\n", time);
        // read
        time = _calc_summary(rRead, resultRead, _REPEAT, progTest, j, nItem, 0, "FastDynamic");
        printf("FastDynamic - read parz: %.3fs\n", time);
        // write
        time = _calc_summary(rWrite, resultWrite, _REPEAT, progTest, j, nItem, 0, "FastDynamic");
        printf("FastDynamic - write parz: %.3fs\n", time);

        progTest++;
#endif
        printf("Done\n");
        fflush(stdout);
    }

    if(progTest < N_TEST_RIEPILOGO) {
        rInsert[progTest].desc[0] = 0;
        rRead[progTest].desc[0] = 0;
        rWrite[progTest].desc[0] = 0;
    }
}

void execute_test_delete(Summary* riepilogo) {
    double time;
    int i, j, progTest;
    unsigned int nItem;
    double result[_REPEAT];
    void *v;
    int obj = 128;

    printf("Execute TEST delete! Repeat for each test: %d\n", _REPEAT);
    progTest = 0;
    for(j = 0; j < N_TEST; j++) {
        nItem = _N_ITEMS_FOR_TEST[j];
        if(nItem > _MAX_DELETE)
            continue;
        progTest = 0;

        printf("Execute test on %d item... \n", nItem);
#ifdef _TEST_EDD_MANN
        for (i = 0; i < _REPEAT; i++) {
            v = _get_edd_mann();
            _test_insert_edd_mann(&obj, nItem, v);
            result[i] = _test_delete_edd_mann(v);
            _clear_edd_mann();
        }
        // delete
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "Edd Mann");
        printf("Edd Mann - delete: %.3fs\n", time);

        progTest++;
#endif
#ifdef _TEST_FAST_DYNAMIC_ARRAY
        for (i = 0; i < _REPEAT; i++) {
            v = _get_fast_dynamic_array();
            _test_insert_fast_dynamic_array(&obj, nItem, v);
            result[i] = _test_delete_fast_dynamic_array(v, nItem);
            _clear_fast_dynamic_array();
        }
        // delete
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FastDynamic");
        printf("FastDynamic - delete: %.3fs\n", time);

        progTest++;
#endif
        printf("Done\n");
        fflush(stdout);
    }

    if(progTest < N_TEST_RIEPILOGO)
        riepilogo[progTest].desc[0] = 0;
}

void execute_test_pop(Summary *riepilogo) {
    double time;
    int i, j, progTest;
    unsigned int nItem;
    double result[_REPEAT];
    void *v;
    int obj = 128;

    progTest = 0;
    printf("Execute TEST pop push! Repeat for each test: %d\n", _REPEAT);
    for(j = 0; j < N_TEST; j++) {
        nItem = _N_ITEMS_FOR_TEST[j];
        printf("Execute test on %d item... \n", nItem);
        progTest = 0;

#ifdef _TEST_FAST_DYNAMIC_ARRAY
        for (i = 0; i < _REPEAT; i++) {
            v = _get_fast_dynamic_array();
            _test_insert_fast_dynamic_array(&obj, nItem, v);
            result[i] = _test_pop_fast_dynamic_array(v, nItem);
            _clear_fast_dynamic_array();
        }
        // pop
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FastDynamic");
        printf("FastDynamic - pop push: %.3fs\n", time);

        progTest++;
#endif
        printf("Done\n");
        fflush(stdout);
    }

    if(progTest < N_TEST_RIEPILOGO)
        riepilogo[progTest].desc[0] = 0;
}

void execute_test_specializations(Summary *riepilogo) {
    double time;
    int i, j, progTest;
    unsigned int nItem;
    double result[_REPEAT];
    // obj is a random value
    int objInt = 128;
    char objChar = 64;
    short int objShortInt = 32;
    long int objLongInt = 128000;
    long long int objLongLongInt = 324145;
    float objFloat = 45.2421;
    double objDouble = 23.34235;
    long double objLongDouble = 45.241254;

    printf("Execute TEST SPECIALIZATIONS! Repeat for each test: %d\n", _REPEAT);
    for(j = 0; j < N_TEST; j++) {
        // execute test on nItem elements
        nItem = _N_ITEMS_FOR_TEST[j];
        progTest = 0;
        printf("Execute test on %d item... \n", nItem);

        /*
         * Repeat the test for _REPEAT times, calculates a mean and stores the result into "riepilogo"
         */

        for (i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_int(objInt, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Int");
        printf("FDA Int - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_char(objChar, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Char");
        printf("FDA Char - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_shortint(objShortInt, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Short Int");
        printf("FDA Short Int - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_longint(objLongInt, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Long Int");
        printf("FDA Long Int - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_longlongint(objLongLongInt, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Long Long Int");
        printf("FDA Long Long Int - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_float(objFloat, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Float");
        printf("FDA Float - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_double(objDouble, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Double");
        printf("FDA Double - RESULT: %.3fs\n", time);
        progTest++;

        for(i = 0; i < _REPEAT; i++)
            result[i] = _test_all_fast_dynamic_array_longdouble(objLongDouble, nItem);
        time = _calc_summary(riepilogo, result, _REPEAT, progTest, j, nItem, 0, "FDA Long Double");
        printf("FDA Long Double - RESULT: %.3fs\n", time);
        progTest++;
    }
}

void print_time(Summary *riepilogo, char descrizione[], const int n) {
    int i, j;

    if(riepilogo[0].desc[0] == 0) {
        printf("Riepilogo non valido!\n");
        return;
    }

    printf("\n");
    for(i = 0; i < 80; i++)
        printf("*");
    printf("\nRIEPILOGO - time (%s):\n\t\t", descrizione);
    for(i = 0; i < N_TEST; i++)
        printf("%d\t", riepilogo[0].result[i].item);
    printf("\n\n");

    for(j = 0; j < n; j++) {
        if(riepilogo[j].desc[0] == 0)
            break;

        printf("%s:\t", riepilogo[j].desc);
#ifdef _TEST_MATUGM
        if(strcmp(riepilogo[j].desc, "Matugm") == 0)
            printf("\t");
#endif
        for (i = 0; i < N_TEST; i++)
            printf("%.3fs\t", riepilogo[j].result[i].time);
        printf("\n");
    }

    for(i = 0; i < 80; i++)
        printf("*");
    printf("\n");
    fflush(stdout);
}

void print_space(Summary *riepilogo) {
    int i, j;

    if(riepilogo[0].desc[0] == 0) {
        printf("Riepilogo non valido!\n");
        return;
    }

    printf("\n");
    for(i = 0; i < 80; i++)
        printf("*");
    printf("\nRIEPILOGO - space (in element):\n\t\t");
    for(i = 0; i < N_TEST; i++)
        printf("%d\t", riepilogo[0].result[i].item);
    printf("\n\n");

    for(j = 0; j < N_TEST_RIEPILOGO; j++) {
        if(riepilogo[j].desc[0] == 0)
            break;

        printf("%s:\t", riepilogo[j].desc);
#ifdef _TEST_MATUGM
        if(strcmp(riepilogo[j].desc, "Matugm") == 0)
            printf("\t");
#endif
        for (i = 0; i < N_TEST; i++)
            printf("%d\t", riepilogo[j].result[i].unused_space);
        printf("\n");
    }

    for(i = 0; i < 80; i++)
        printf("*");
    printf("\n");
    fflush(stdout);
}

void init(Summary *riepilogo) {
    int i, j;
    for(i = 0; i < N_TEST_RIEPILOGO; i++) {
        memset(riepilogo[i].desc, 0, sizeof(riepilogo[i].desc));
        for (j = 0; j < N_TEST; j++) {
            riepilogo[i].result[j].item = 0;
            riepilogo[i].result[j].time = 0;
            riepilogo[i].result[i].unused_space = 0;
        }
    }
}

double _media(double *v, int n) {
    double somma = 0;
    int i;
    for(i = 0; i < n; i++)
        somma += v[i];
    return somma / n;
}

double _calc_summary(Summary *summary, double *v, const int n, const int progTest, const int j, unsigned const int nItem,
        unsigned const int unusedSpace, char *descr) {
    double time = _media(v, n);
    strcpy(summary[progTest].desc, descr);
    summary[progTest].result[j].time = time;
    summary[progTest].result[j].item = nItem;
    summary[progTest].result[j].unused_space = unusedSpace;
    return time;
}