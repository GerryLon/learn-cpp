#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <cassert>

namespace ds {

template <class T>
class MyStack {
public:
    MyStack(int capacity) {
        assert(capacity > 0);
        this->m_iCapacity = capacity;
        this->m_pStack = new T[this->m_iCapacity];
        this->m_iTop = -1; // 指向栈顶的元素
    }

    ~MyStack() {
        this->cleanStack();
        if (this->m_pStack) {
            delete []this->m_pStack;
        }
    }

    int cleanStack() {
        this->m_iTop = 0;
        return 0;
    }

    bool stackEmpty() const {
        return this->m_iTop == -1;
    }

    bool stackFull() const {
        return this->m_iTop == this->m_iCapacity - 1;
    }

    int stackLength() const {
        return this->m_iTop + 1;
    }

    bool pop(T& element) {
        if (this->stackEmpty()) {
            return false;
        }
        element = this->m_pStack[this->m_iTop--];
        return true;
    }

    bool push(T element) {
        if (this->stackFull()) {
            return false;
        }
        this->m_pStack[++this->m_iTop] = element;
        return true;
    }

    int stackTraverse(bool (*visit)(T& element)) {
        for (int i = 0, len = this->stackLength(); i < len; i++) {
            if (!visit(this->m_pStack[i])) {
                break;
            }
        }
        return 0;
    }

private:
    T* m_pStack;
    int m_iCapacity;
    int m_iTop; // 指向栈顶
};

}

#endif // MYSTACK_H_INCLUDED
