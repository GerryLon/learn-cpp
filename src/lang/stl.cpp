#include "../../include/lang/stl.h"
#include <vector>
#include <list>
#include <string>
#include <map>

static int test_vector() {
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

static int test_list() {
    list<int> v;
    const int len = 10;
    for (int i = 1; i <= len; i++) {
        v.push_back(i);
    }

    assert(v.size() == len);

    v.pop_back();
    assert(v.size() == len - 1);

    for (int i = 1; i <= len - 1; i++) {
        // assert(v[i] == i + 1); // list[i] error
    }

    list<int>::iterator iter = v.begin();
    for (; iter != v.end(); iter++) {
        // cout << *iter << endl;
    }

    assert(v.front() == 1);
    assert(v.back() == 9);
    return 0;
}

static int test_map() {
    map<string, string> m;
    pair<string, string> p("hello", "world");
    pair<string, string> p2("shanghai", "»¦");
    m.insert(p);
    m.insert(p2);

    assert(m.size() == 2);
    assert(m["hello"] == "world");
    assert(m["shanghai"] == "»¦");

    map<string, string>::iterator iter = m.begin();
    for(; iter != m.end(); iter++) {
        // cout << iter->first << "=" << iter->second << endl;
    }
    return 0;
}

int test_stl() {
    test_vector();
    test_list();
    test_map();
    return 0;
}
