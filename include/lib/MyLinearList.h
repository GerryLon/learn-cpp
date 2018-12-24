#ifndef LIB_MYLINEARLIST_H
#define LIB_MYLINEARLIST_H

#include <cassert>

namespace ds {

template <class T>
class MyLinearList {

public:
    MyLinearList(int capacity = 10) {
        assert(capacity > 0);
        this->m_iCapacity = capacity;
        this->m_pArr = new T[capacity];
        this->ClearList();
    }

    ~MyLinearList() {
        if (this->m_pArr) {
            this->ClearList();
            delete []this->m_pArr;
        }
    }

    inline int ClearList() {
        this->m_iLength = 0;
        return 0;
    }

    inline bool ListEmpty() const {
        return this->m_iLength == 0;
    }

    inline bool ListFull() const {
        return this->m_iLength == this->m_iCapacity;
    }

    inline int ListLength() const {
        return this->m_iLength;
    }

    // get element at i, assign it to elem
    bool GetElem(int i, T& elem) const {
        if (i < 0 || i > this->ListLength() - 1) {
            return false;
        }
        elem = this->m_pArr[i];
        return true;
    }

    int LocateElem(T elem) const {
        int ret = -1;
        for (int i = 0, len = this->ListLength(); i < len; i++) {
            if (elem == this->m_pArr[i]) { // T类型必须重载==
                return i;
            }
        }
        return ret;
    }

    bool PriorElem(T curr, T& elem) const {
        int index = this->LocateElem(curr);
        if (index <= 0) { // 当前元素在第一个或者不在列表中, 无前驱
            return false;
        }

        elem = this->m_pArr[index - 1];
        return true;
    }

    bool NextElem(T curr, T& elem) const {
        int index = this->LocateElem(curr);
        if (index < 0 || index >= this->ListLength() - 1) { // 当前元素在最后一个或者不在列表中, 无前驱
            return false;
        }

        elem = this->m_pArr[index + 1];
        return true;
    }

    // insert elem to position index
    bool ListInsert(int index, T elem) {
        if (index < 0 || index > this->ListLength()) {
            return false;
        }

        if (this->ListFull()) {
            return false;
        }

        for (int i = this->ListLength() - 1; i >= index; i--) {
            this->m_pArr[i + 1] = this->m_pArr[i];
        }

        this->m_pArr[index] = elem;
        this->m_iLength++;
        return true;
    }

    bool ListDelete(int index, T& elem) {
        if (index < 0 || index > this->ListLength() - 1) {
            return false;
        }

        if (this->ListEmpty()) {
            return false;
        }

        elem = this->m_pArr[index];
        for (int i = index + 1, len = this->ListLength(); i < len; i++) {
            this->m_pArr[i - 1] = this->m_pArr[i];
        }
        this->m_iLength--;
        return true;
    }

    int ListTraverse(bool (*visit)(T& elem), bool withNewLine = true) const {
        for (int i = 0, len = this->ListLength(); i < len; i++) {
            if (!visit(this->m_pArr[i])) {
                break;
            }
        }
        if (withNewLine) {
            cout << endl;
        }
        return 0;
    }

private:
    T* m_pArr;
    int m_iCapacity;
    int m_iLength;
};

}

#endif // LIB_MYLINEARLIST_H
