#include <iostream>
using namespace std;

int printErrMsg(const char* filename, const char* func, const unsigned int line) {
    cout << __TIME__ << " err: " << filename << ", " << func << "(), line: " << line << endl;
    return 0;
}
