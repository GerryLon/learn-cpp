#include "../include/common/common.h"
#include "../include/lib/MyQueue.h"
#include "../include/lib/MyStack.h"
#include "../include/lib/MyLinearList.h"
#include "../include/lib/MyLinkedList.h"
#include "../include/lib/MyLinkedList.h"
#include "lib_test.h"
#include <string.h>
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
    string str;

    assert(s.stackEmpty());
    assert(!s.peek(str));

    assert(s.push("aa"));
    assert(s.peek(str));
    assert(str == "aa");

    assert(s.push("bb"));
    assert(s.push("cc"));

    assert(s.peek(str));
    assert(str == "cc");
    assert(s.stackLength() == 3);
    assert(!s.stackEmpty());
    // s.stackTraverse(printElement);
    // s.stackTraverse(printElement, false);

    s.pop(str);
    assert(str == "cc");

    s.pop(str);
    assert(str == "bb");

    s.pop(str);
    assert(str == "aa");

    assert(!s.peek(str));
    assert(s.stackEmpty());
    s.clearStack();
    assert(s.stackEmpty());

    return 0;
}

// decimal to radix
// radix: [2, 36]
static string radixTransform(int num, int radix) {
    const char* meta = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";

    if (radix < 2 || radix > 36) {
        return "";
    }

    while (num != 0) {
        string s(1, meta[num % radix]);
        result = s + result;
        num = num / radix;
    }

    return result;
}

static int test_radixTransform() {
    string result = radixTransform(5, 2);
    assert(result == "101");

    result = radixTransform(255, 16);
    assert(result == "FF");
    return 0;
}

static bool isBracket(char c) {
    return c == '('
        || c == '['
        || c == '{'
        || c == ')'
        || c == ']'
        || c == '}';
}

static bool bracketsMatch(const char* str) {
    if (!str) {
        return true;
    }

    char* p = (char*)str;
    MyStack<char> s(strlen(str));
    char need = '\0';
    char tmp;
    char charmap[128];
    charmap['('] = ')';
    charmap['['] = ']';
    charmap['{'] = '}';

    while (*p) {
        if (!isBracket(*p)) {
            p++;
            continue;
        }
        if (*p != need) { // [({}
            s.push(*p);
            need = charmap[(int)*p];
        } else {
            s.pop(tmp);
            if (s.peek(tmp)) {
                need = charmap[(int)tmp];
            }
        }
        p++;
    }

    return s.stackEmpty();
}

static int test_bracketsMatch() {
    assert(bracketsMatch("hello ()world[c++{()}]"));
    assert(bracketsMatch("()[{({()})}]"));
    assert(!bracketsMatch("()[{({)})}]"));

    return 0;
}

static int test_MyLinearList() {
    MyLinearList<int> list(5);
    int a;

    assert(list.ListEmpty());
    assert(list.ListLength() == 0);

    list.ListInsert(0, 1); // 1
    list.ListInsert(0, 2); // 2, 1
    list.ListInsert(0, 3); // 3, 2, 1
    list.ListInsert(3, 4); // 3, 2, 1, 4

    // list.ListTraverse(printElement);

    a = 3;
    assert(list.LocateElem(a) == 0);
    assert(!list.ListFull());
    list.ListInsert(2, 5); // 3, 2, 5, 1, 4
    // list.ListTraverse(printElement);
    assert(list.ListFull());

    list.GetElem(3, a); // get will return 1
    assert(a == 1);

    list.PriorElem(2, a);
    assert(a == 3);

    list.NextElem(2, a);
    assert(a == 5);

    while(!list.ListEmpty()) {
        list.ListDelete(list.ListLength() - 1, a); // 4, 1, 5, 2, 3
    }
    assert(a == 3);
    list.ListTraverse(printElement);
    assert(list.ListEmpty());

    return 0;
}

template <class T>
static bool visitNode(Node<T>& node) {
    cout << node.data << endl;
    return true;
}

static int test_MyLinkedList() {
    MyLinkedList<string> list;
    Node<string> tmp;
    assert(list.ListLength() == 0);
    assert(list.ListEmpty());

    Node<string> node1 = Node<string>("aa");
    list.ListInsert(0, &node1);
    assert(list.ListLength() == 1);
    assert(!list.ListEmpty());

    Node<string> node2 = Node<string>("bb");
    list.ListInsert(1, &node2); // aa->bb
    assert(list.ListLength() == 2);

    Node<string> node3 = Node<string>("cc");
    list.ListInsert(2, &node3); // aa->bb->cc
    assert(list.ListLength() == 3);

    // list.ListTraverse(visitNode);

    assert(list.GetElem(1, &tmp));
    assert(tmp.data == "bb");

    assert(!list.GetElem(9999, &tmp));

    assert(list.LocateElem(&node3) == 2);

    list.ListDelete(0, &tmp);
    assert(list.ListLength() == 2);
    assert(tmp.data == "aa");

    // list.ListTraverse(visitNode);

    list.ListDelete(0, &tmp);
    assert(list.ListLength() == 1);
    assert(tmp.data == "bb");

    list.ListDelete(0, &tmp);
    assert(list.ListLength() == 0);
    assert(tmp.data == "cc");
    list.ClearList();
    return 0;

}

int test_lib() {
    test_MyQueue();
    test_MyStack();
    test_radixTransform();
    test_bracketsMatch();
    test_MyLinearList();
    test_MyLinkedList();
    return 0;
}
