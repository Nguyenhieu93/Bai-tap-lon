#ifndef LIST_CPP
#define LIST_CPP
#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

template<typename T>
class List {
private:
    node<T> *head;
    node<T> *tail;
    int len;
public: 
    List() : head(nullptr), tail(nullptr), len(0){}
    List(T val) {
        node<T> *newNode = new node<T>(val);
        head = tail = newNode;
        len = 1;
    }
    
    int size() {
        return len;
    }
    
    T back() {
        return tail->getData();
    }
    
    T front() {
        return head->getData();
    }
    
    bool empty() {
        return len == 0;
    }
    
    void push_back(T val) {
        node<T> *newNode = new node<T>(val);
        if(empty()) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
        len++;
    }
    
    void push_front(T val) {
        node<T> *newNode = new node<T>(val);
        if(empty()) {
            head = tail = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
        len++;
    }
    
    void pop_back() {
        if(empty()) return;
        node<T> *tmp = head;
        while(tmp->getNext() != tail) tmp = tmp->getNext();
        delete tail;
        tail = tmp;
        tail->setNext(nullptr);
        len--;
    }
    
    void pop_front() {
        if(len == 0) return;
        node<T> *tmp = head;
        head = head->getNext();
        delete tmp;
        len--;
    }
    
    void insert(int pos, T val) {
        if(pos < 0 || pos > len) return;
        if(len == 0) push_back(val);
        if(len == 1) push_front(val);
        else {
            node<T> *newNode = new node<T>(val);
            node<T> *tmp = head;
            for(int i=1; i<pos-1; i++) {
                tmp = tmp->getNext();
            }
            newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);
        }
        len++;
    }
    
    void erase(int pos) {
        if(pos < 0 || pos > len) return;
        if(len == 0) return;
        if(len == 1) pop_back();
        else {
            node<T> *tmp = head;
            node<T> *tmp1 = head;
            for(int i=1; i<pos-1; i++) {
                tmp = tmp->getNext();
                tmp1 = tmp1->getNext();
            }
            tmp1 = tmp1->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            delete tmp1;
        }
        len--;
    } 
      
    void sort() {
        for(node<T> *i = head; i != nullptr; i = i->getNext()) {
            for(node<T> *j = i->getNext(); j != nullptr; j=j->getNext()) {
                if(i->getData() > j->getData()) {
                    T tmp = i->getData();
                    i->setData(j->getData());
                    j->setData(tmp);
                }
            }
        }
    }

    class iterator {
    private:
        node<T> *ptr;
    public:
        iterator(node<T> *p) : ptr(p) {}
        node<T> *getPtr() {return ptr;}
        bool operator!=(iterator other) {
            return this->ptr != other.ptr;
        }
        iterator operator++() {
            ptr = ptr->getNext();
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ptr = ptr->getNext();
            return tmp;
        }
        T operator*() {
            return ptr->getData(); 
        }
    };  
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    }
};

#endif