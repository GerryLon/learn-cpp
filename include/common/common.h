#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

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

int printErrMsg(const char* filename, const char* func, const unsigned int line);

template <class T>
bool printElement(T& element) {
    cout << element << endl;
    return true;
}

#endif // _COMMON_H
