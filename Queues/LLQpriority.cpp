#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int age;
    int priority;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(string name, int age, int priority) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->age = age;
    newNode->priority = priority;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << name << " (Age: " << age << ", Priority: " << priority << ") added to the queue." << endl;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }

    // Find the node with the highest priority
    Node *temp = front, *prev = nullptr, *maxNode = front, *maxPrev = nullptr;
    while (temp != nullptr) {
        if (temp->priority > maxNode->priority) {
            maxNode = temp;
            maxPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    // Remove the highest-priority node
    if (maxPrev == nullptr) { // maxNode is the front node
        front = front->next;
        if (front == nullptr) rear = nullptr;
    } else {
        maxPrev->next = maxNode->next;
        if (maxNode == rear) rear = maxPrev; // Update rear if needed
    }

    cout << maxNode->name << " (Age: " << maxNode->age << ", Priority: " << maxNode->priority 
         << ") removed from the queue." << endl;
    delete maxNode;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue elements:" << endl;
    while (temp != nullptr) {
        cout << temp->name << " (Age: " << temp->age << ", Priority: " << temp->priority << ")" << endl;
        temp = temp->next;
    }
}

int main() {
    int choice, age, priority;
    string name;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter priority: ";
                cin >> priority;
                enqueue(name, age, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
