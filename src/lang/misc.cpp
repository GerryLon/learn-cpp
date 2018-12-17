#include "common/common.h"

static test_threeOps() {
    int a = 10;
    int b = 20;
    (a < b ? a : b) = 30;
    if (a != 30) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }

    return 0;
}

static int test_const() {
    int a = 1;
    int b = 2;

    const int* p1 = &a;
    int* const p2 = &b;

    // *p1 = 3; // error: read-only location '* p1'
    p1 = &b; // ok, *p1 = 2

    // p2 = &a; // error: read-only variable 'p2'
    *p2 = a; // b = a, *p2 = a = 1, *p1 = 1

    if (*p1 != 1) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }

    if (*p2 != 2) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }

    return 0;
}

int test_misc() {
    test_threeOps();
    test_const();

    return 0;
}
