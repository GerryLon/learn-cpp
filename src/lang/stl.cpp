#include "stl.h"
#include <vector>

int test_vector() {
    vector<int> v;
    const int len = 10;
    for (int i = 1; i <= len; i++) {
        v.push_back(i);
    }

    assert(v.size() == len);

    v.pop_back();
    assert(v.size() == len - 1);

    for (int i = 1; i <= len - 1; i++) {
        assert(v[i] == i + 1); // 0-1 1-2 i-i+1
    }

    vector<int>::iterator iter = v.begin();
    for (; iter != v.end(); iter++) {
        // cout << *iter << endl;
    }

    assert(v.front() == 1);
    assert(v.back() == 9);
    return 0;
}

int test_stl() {
    test_vector();
    return 0;
}
