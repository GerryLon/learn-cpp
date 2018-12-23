#include "common/common.h"
#include "MyQueue.h"
#include "lib_test.h"
using namespace std;
using namespace ds;

// print number great than 1
static bool gt1(int& a) {
    if (a > 1) {
        cout << a << endl;
    }

    return true;
}

static int test_MyQueue() {
    int i = 0;
    MyQueue<int> q(3);
    assert(q.QueueEmpty());

    q.EnQueue(1);
    q.EnQueue(2);
    assert(q.QueueLength() == 2);
    q.EnQueue(3);
    assert(q.QueueFull());

    // q.QueueTraverse(printElement);
    // q.QueueTraverse(gt1);

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

int test_lib() {
    test_MyQueue();
    return 0;
}
