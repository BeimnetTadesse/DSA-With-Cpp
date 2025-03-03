#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;  
        rear = newNode;         
    }
    cout << value << " added to the queue." << endl;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
    } else {
        Node* temp = front;
        front = front->next;   
        cout << temp->data << " removed from the queue." << endl;
        delete temp;   
        if (front == nullptr) rear = nullptr;   
    }
}

void peek() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Front element: " << front->data << endl;
    }
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
    } else {
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
