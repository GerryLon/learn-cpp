#include <iostream>
using namespace std;

int printErrMsg(const char* filename, const char* func, const int line) {
    cout << "err: " << filename << ", " << func << "(), line: " << line << endl;
    return 0;
}
