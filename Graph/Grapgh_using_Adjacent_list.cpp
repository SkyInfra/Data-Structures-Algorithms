#include<iostream>
using namespace std;

struct Edge {
    int value;
    Edge* next;

    Edge(int v) {
        value = v;
        next = NULL;
    }
};

struct Node {
    int value;
    Edge* head;
    Edge* tail;
    Node* next;

    Node(int v) {
        value = v;
        head = tail = NULL;
        next = NULL;
    }
};
