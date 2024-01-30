#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;


    //constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertInBeginning(int value) {
        Node* newNode = new Node(value); // creating a new node
        newNode->next = head; // new node next (pointer) towards the head
        head = newNode; // new node becomes the head pointer
    }

    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteLast() {
        // IF only one node present
        if (head) {
            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }

            // Traversing to second last node 
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next; // deleting the last node
            current->next = nullptr; // updating the pointer of last node to NULLPTR
        }
    }

    void print() {
        Node* current = head;
        if (current) {
            while (current != nullptr) {
                cout << current->data; // printing nodes data
                if (current->next) {
                    cout << ", ";
                }
                current = current->next;
            }
            cout << endl;
        } else {
            cout << "Linked list is empty!" << std::endl;
        }
    }
};

int main() {
    LinkedList linkedList;
    
    linkedList.insertInBeginning(60);
    linkedList.insertInBeginning(40);
    linkedList.insertInBeginning(20);
    
    cout<<"Items in the linked list: ";
    linkedList.print();
    
    linkedList.deleteFirst();
    cout<<"Items in the linked list after deleting the first element: ";
    linkedList.print();
    
    linkedList.deleteLast();
    cout<<"Items in the linked list after deleting the last element: ";
    linkedList.print();
    
    return 0;
}
