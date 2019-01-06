#include "../../include/lang/stl.h"
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <string>
#include <map>
#include <algorithm>

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

    v.erase(v.begin(), v.begin() + 3);
    assert(v.size() == 6);
    assert(v.front() == 4);
    assert(v.back() == 9);
    return 0;
}

static int test_deque() {
    deque<int> dq;
    const int num = 10;

    for (int i = 0; i < num; i++) {
        dq.push_front(i);
    }

    for (int i = 0; i < num; i++) {
        assert(dq.front() == num - 1 - i); // 9 8 ... 1
        dq.pop_front();
    }

    for (int i = 0; i < num; i++) {
        dq.push_back(i);
    }

    assert(dq.size() == num);

    for (int i = 0; i < num; i++) {
        assert(dq.back() == num - 1 - i); // 9 8 ... 1
        dq.pop_back();
    }

    return 0;
}

// 十进制转2-36进制
static string decimalToAny(int num, int base) {
    assert(num >= 0);
    assert(base >= 2 && base <= 36);
    stack<char> s;
    const char* mapping = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"; // 0 -> 36

    // string source(str);
    // transform(source.begin(), source.end(), source.begin(), ::toupper); // toupper

    while (num != 0) {
        s.push(mapping[num % base]);
        num = num / base;
    }

    if (s.empty()) {
        return string(1, mapping[num]);
    }

    string dst;
    while (!s.empty()) {
        dst = dst + s.top();
        s.pop();
    }

    return dst;
}

static int test_stack() {
    assert(decimalToAny(100, 16) == "64");

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
    test_deque();
    test_stack();
    test_list();
    test_map();
    return 0;
}
