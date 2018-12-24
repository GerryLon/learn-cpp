#include "../../include/common/common.h"
#include "../../include/lang/Location.h"
#include "../../include/lib/MyString.h"
#include "../../include/lang/Worker.h"
#include <cassert>
#include <typeinfo>

class C {

public:
    // overload ==
    bool operator==(int i) const {
        return this->m_a == i;
    }

    /* explicit */ C(int i = 0) {
        m_a = i;
    }

private:
    int m_a;
};

static int test_explicit() {
    C c;
    c = 2; // C的构造函数有explicit时, 会报错
    assert(c == 2);
    return 0;
}

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
//    loc.name = "sz"; // access protected error
    return loc;
}

static int test_Location() {
    Location loc = _returnLocation();
    return 0;
}

static int test_print_self() {
    // ofstream outfile("misc.cpp");
    ifstream infile(__FILE__);

    if (!infile) {
        cerr << "error: unable to open input file!\n";
        return -1;
    }
//    if (!outfile ) {
//        cerr << "error: unable to open output file!\n";
//        return -2;
//    }

    string word;
    while (infile >> word) {
        // outfile << word << ' ';
        // cout << word << ' '; // remove this comment
    }
    cout << endl;

    if (infile) {
        infile.close();
    }

    return 0;
}

static int test_new() {
    int* arr = new int[10];
    if (!arr) {
        printErrMsg(__FILE__, __func__, __LINE__);
        return -1;
    }

    if (arr) {
        delete []arr;
    }

    return 0;
}

static int test_MyString() {
    MyString s1 = "hello";
    assert(s1 == "hello");
    assert(s1 > "hella");

    MyString s2(s1);
    assert(s1 == s2);

    s1 += " world";
    assert(s1 == "hello world");
    assert(s1 != s2);

    s2 = s2 + " world";
    assert(s1 == s2);

    // cout << s1 << " " << s2 << endl;
    return 0;
}

int test_inherit(bool open) {
    if (!open) {
        return 0;
    }
    Worker w = Worker("tom", 100);
    w.print();

    Worker w2 = Worker("jerry", 200);
    w2.print();
    w.print();

    Person* p = new Worker("tom", 100);
    p->print();

    return 0;
}

int test_misc() {
    test_explicit();
    test_threeOps();
    test_const();
    test_const2();
    test_reference();
    test_default_param();
    test_inline();
    test_Location();
    test_print_self();
    test_new();
    test_MyString();
    test_inherit(false);

    return 0;
}
