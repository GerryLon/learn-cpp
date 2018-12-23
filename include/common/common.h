#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int printErrMsg(const char* filename, const char* func, const unsigned int line);

template <class T>
bool printElement(T& element) {
    cout << element << endl;
    return true;
}

#endif // _COMMON_H
