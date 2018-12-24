#include "../include/common/common.h"
#include "../include/lib/MyQueue.h"
#include "../include/lib/MyStack.h"
#include "lib_test.h"
using namespace std;
using namespace ds;

// print number great than some number
static bool gt(int& a) {
    if (a > 10) {
        cout << a << endl;
    }

    return true;
}

static int test_MyQueue() {
    int i = 0;
    MyQueue<int> q(3);
    assert(q.QueueEmpty());

    assert(q.EnQueue(1));
    assert(q.EnQueue(2));
    assert(q.QueueLength() == 2);
    assert(q.EnQueue(3));
    assert(q.QueueFull());

    // q.QueueTraverse(printElement);
    q.QueueTraverse(gt);

    q.DeQueue(i);
    assert(i == 1);

    // 2, 3
    // q.QueueTraverse(printElement);
    // cout << endl;

    q.DeQueue(i);
    assert(i == 2);
    // 3
    // q.QueueTraverse(printElement);

    q.DeQueue(i);
    assert(i == 3);

    assert(q.QueueEmpty());

    return 0;
}

static int test_MyStack() {
    MyStack<string> s(3);
    assert(s.stackEmpty());
    assert(s.push("aa"));
    assert(s.push("bb"));
    assert(s.push("cc"));

    assert(s.stackLength() == 3);
    assert(!s.stackEmpty());
    // s.stackTraverse(printElement);

    string str;
    s.pop(str);
    assert(str == "cc");

    s.pop(str);
    assert(str == "bb");

    s.pop(str);
    assert(str == "aa");

    assert(s.stackEmpty());

    return 0;
}

int test_lib() {
    test_MyQueue();
    test_MyStack();
    return 0;
}
