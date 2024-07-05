//
// Created by 朱俊驰 on 7/5/24.
//
# include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

// parameterized constructor with next node
    Node (int value, Node *node= nullptr):data(value), next(node){}

// parameterized constructor
    Node(int value):data(value), next(nullptr){}

// default constructor
    Node():data(0), next(nullptr){}
};

int main(){

}
