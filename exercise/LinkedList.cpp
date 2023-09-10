#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(const int& v = 0) : value(v), next(nullptr) { cout << "Node created with value=" << value << " at address: " << this << endl; }
    ~Node() { cout << "Node destroyed at address: " << this << endl; }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) { }
    ~LinkedList() { }

    void insertNode(const int& v) {
        Node* newNode = new Node(v);
        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }

    Node* findFirstNodeByValue(const int& v) {
        Node* current = head;
        try {
            while(current->value != v) {
                current = current->next;
            }
        }catch(const std::exception& e) {
            cout << "Exception. No value found.";
            return nullptr;
        }

        return current;
    }

    void removeLastNode() {
        Node* previous = nullptr;
        Node* current = head;
        while (current->next != nullptr) {
            previous = current; 
            current = current->next;
        }
        if(previous != nullptr) previous->next = nullptr;
        delete current;
    }

    void listNodes() {
        Node* current = head;
        int i = 0;
        while(current != nullptr) {
            i += 1;
            cout << i << ". with value " << current->value << endl;
            current = current->next; 
        }
    }
};

int main()
{
    LinkedList* list = new LinkedList();
    list->insertNode(1);
    list->insertNode(3);
    list->insertNode(5);
    list->insertNode(11);
    list->listNodes();
    list->removeLastNode();
    list->listNodes();
    if(list->findFirstNodeByValue(12) == nullptr) cout << "12 is not in the list" << endl;

    double b{16.4};

    return 0;
}

// !! ALLES POINTER !!