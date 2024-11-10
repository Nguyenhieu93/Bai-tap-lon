#ifndef NODE_CPP
#define NODE_CPP
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class node {
private:
    T data;
    node* next;
public:
    node(T val = T(), node *nex=nullptr) : data(val), next(nex) {}
    T getData() {return data;}
    node<T> *getNext() {return next;}
    void setData(T val) {data = val;}
    void setNext(node<T> *nex) {next = nex;} 
};

#endif