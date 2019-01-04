#ifndef LIB_MYLINKEDLIST_H
#define LIB_MYLINKEDLIST_H

// 双向循环链表, head, tail不包含有效数据

#include <cassert>

namespace ds {

template <class T>
class Node {
public:
    Node(): prev(NULL), next(NULL) {}
    Node(T d): data(d), prev(NULL), next(NULL) {}
    Node(T d, Node* p, Node* n): data(d), prev(p), next(n) {}
    Node(Node* p, Node* n): prev(p), next(n) {}

public:
    T data;
    Node* prev;
    Node* next;
};

template <class T>
class MyLinkedList {
public:
MyLinkedList() {
    Node<T>* node = new Node<T>(NULL, NULL);

    head = tail = node;
    reset();
}

~MyLinkedList() {
    ClearList();
    delete head;
    head = NULL;

    delete tail;
    tail = NULL;
}

int reset() {
    head->next = head->prev = tail;
    tail->prev = tail->next = head;
    this->m_iLength = 0;
    return 0;
}

int ClearList() {
    if (ListEmpty()) {
        return 0;
    }

    Node<T>* currNode = head->next;
    Node<T>* tmp;

    // delete nodes except head and tail
    while (currNode != tail) {
        tmp = currNode->next;
        delete currNode;
        currNode = tmp;
    }
    reset();
    return 0;
}

bool ListEmpty() const {
    return this->m_iLength == 0;
}

int ListLength() const {
    return this->m_iLength;
}

bool GetElem(int index, Node<T>* node /* out */) const {
    if (index < 0 || index >= this->m_iLength) {
        return false;
    }

    if (this->ListEmpty()) {
        return false;
    }

    Node<T>* tmp = this->head->next;
    int i = 0;
    for (; i < index; i++, tmp = tmp->next) {
        ;
    }

    *node = *tmp;
    return true;
}

int LocateElem(Node<T>* node /* in */) const {
    if (this->ListEmpty()) {
        return -1;
    }

    if (!node) {
        return -1;
    }

    Node<T>* tmp = this->head->next;
    int i = 0;
    while (tmp != tail && tmp->data != node->data) {
        tmp = tmp->next;
        i++;
    }
    return tmp == tail ? -1 : i;
}

bool PriorElem(Node<T>* curr /* in */, Node<T>* prevNode /* out */) const {
    if (this->ListEmpty() || !curr) {
        return false;
    }

    if (!this->LocateElem(curr)) {
        return false;
    }

    if (curr->prev && curr->prev != head) {
        *prevNode = curr->prev;
        return true;
    }
    return false;
}

bool NextElem(Node<T>* curr /* in */, Node<T>* nextNode) {
    if (this->ListEmpty() || !curr) {
        return false;
    }

    if (!this->LocateElem(curr)) {
        return false;
    }

    if (curr->next && curr->next != tail) {
        *nextNode = curr->next;
        return true;
    }
    return false;
}

bool ListInsert(int index, Node<T>* node) {

    if (index < 0 || index > this->ListLength()) { // valid: [0, length]
        return false;
    }

    if (node == NULL) {
        return false;
    }

    Node<T>* target = NULL;
    int i = 0;
    for (target = head->next; i < index; target = target->next, i++) {
        ;
    }

    node->prev = target->prev;
    target->prev->next = node;
    node->next = target;
    target->prev = node;

    this->m_iLength++;
    return true;
}

bool ListDelete(int index, Node<T>* node) {
    if (!this->GetElem(index, node)) {
        return false;
    }

    Node<T>* target = node;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete target;
    this->m_iLength--;
    return true;
}

int ListTraverse(bool (*visit)(Node<T>& node), bool fromHead = true) {
    if (this->ListEmpty()) {
        return -1;
    }

    Node<T>* tmp;

    if (fromHead) {
        for (tmp = this->head->next; tmp != NULL && tmp != this->tail; tmp = tmp->next) {
            if (!visit(*tmp)) {
                break;
            }
        }
    } else {
        for (tmp = this->tail->prev; tmp != NULL && tmp != this->head; tmp = tmp->prev) {
            if (!visit(*tmp)) {
                break;
            }
        }
    }
    return 0;
}

private:
    Node<T>* head;
    Node<T>* tail;
    int m_iLength;
};
}


#endif // LIB_MYLINKEDLIST_H
