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
class Graph {
    Node* head;
    Node* tail;

public:
    Graph() {
        head = tail = NULL;
    }

    void insert_value(int v) {
        Node* newNode = new Node(v);

        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* check_vertex(int v) {
        Node* temp = head;

        while(temp != NULL && temp->value != v) {
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "Not Found\n";
            return NULL;
        }

        return temp;
    }

    void add_edge(int u, int v) {
        Node* temp = check_vertex(u);

        if(temp == NULL) {
            cout << "No Source Found\n";
            return;
        }

        Edge* newNode = new Edge(v);

        if(temp->head == NULL) {
            temp->head = temp->tail = newNode;
        }
        else {
            temp->tail->next = newNode;
            temp->tail = newNode;
        }
    }
 void display() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->value << " -> ";

            Edge* newEdge = temp->head;

            while(newEdge != NULL) {
                cout << newEdge->value << " ";
                newEdge = newEdge->next;
            }

            cout << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Graph g;

    g.insert_value(1);
    g.insert_value(2);
    g.insert_value(3);
    g.insert_value(4);

    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,4);

    g.display();

    return 0;
}
