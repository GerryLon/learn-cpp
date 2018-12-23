#ifndef LIB_MYQUEUE_H
#define LIB_MYQUEUE_H

// 模板类定义和实现要写在一个文件里
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

#include "common/common.h"

// ring queue
namespace ds {

template <class T>
class MyQueue
{
    public:
        MyQueue(int capacity) {
            assert(capacity > 0);
            this->m_iCapacity = capacity;
            this->m_pQueue = new T[capacity];
            // this->m_iLength = 0;
            this->ClearQueue();
        }
        virtual ~MyQueue() {
            this->m_iCapacity = 0;
            this->m_iLength = 0;
            if (this->m_pQueue) {
                delete []m_pQueue;
                m_pQueue = NULL;
            }
        }
        int ClearQueue() {
            // this->m_iCapacity = 0;
            this->m_iLength = 0;
            this->m_iHead = 0;
            this->m_iTail = 0;
//            for (T* p = this->m_pQueue; p; p++) {
//                memset(p, 0, sizeof(T));
//            }
            return 0;
        }
        bool QueueEmpty() const {
            return this->m_iLength == 0;
        }

        int QueueLength() const {
            return this->m_iLength;
        }

        bool QueueFull() const {
            return this->m_iLength == this->m_iCapacity;
        }

        bool EnQueue(T element) {
            if (this->QueueFull()) {
                return false;
            }

            this->m_pQueue[this->m_iTail] = element;
            this->m_iTail++;
            this->m_iTail = this->m_iTail % this->m_iCapacity;
            this->m_iLength++;
            return true;
        }

        bool DeQueue(T& element) {
            if (this->QueueEmpty()) {
                return false;
            }
            element = this->m_pQueue[m_iHead];
            this->m_iHead++;
            this->m_iHead = this->m_iHead % this->m_iCapacity;
            this->m_iLength--;
            return true;
        }

        // visit() return false means exit QueueTraverse()
        int QueueTraverse(bool (*visit)(T& element)) {
            for (int i = 0; i < this->m_iLength; i++) {
                if (!visit(this->m_pQueue[i % this->m_iLength])) {
                    break;
                }
            }
            return 0;
        }

    protected:

    private:
        T* m_pQueue;
        int m_iCapacity;
        int m_iLength;
        int m_iHead;
        int m_iTail;
};

#endif // LIB_MYQUEUE_H
}
