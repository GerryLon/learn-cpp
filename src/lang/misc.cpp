#include "common/common.h"
#include "Location.h"

static int test_threeOps() {
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

    if (*p2 != 1) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }

    return 0;
}

static int test_const2() {
    const int a = 1;
    int* p = (int*)&a;

    *p = 2; // in c lang, a is 2 now, but in c++, a is also 1.

    if (a != 1) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }

    return 0;
}

static int _returnInt() {
    int a = 10;
    return a;
}

static int test_reference() {
    _returnInt();
    // int a1 = _returnInt();

    // invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    // int& a2 = _returnInt();
    // int a2 = 0;
    // cout << a1 << " " << a2 << endl;

    return 0;
}

static int test_default_param(int a = 3) {
    if (a != 3) {
        printErrMsg(__FILE__, __func__, __LINE__);
    }
    return 0;
}

static int _inline_max(int a, int b) {
    return a > b ? a : b;
}

static inline int test_inline() {
    if (_inline_max(2, 3) != 3) {
        printErrMsg(__FILE__, __func__, __LINE__);
        return -1;
    }
    return 0;
}

Location _returnLocation() {
    Location loc(1, 2);
    return loc;
}

static int test_Location() {
    Location loc = _returnLocation();
    return 0;
}

int test_misc() {
    test_threeOps();
    test_const();
    test_const2();
    test_reference();
    test_default_param();
    test_inline();
    test_Location();

    return 0;
}
