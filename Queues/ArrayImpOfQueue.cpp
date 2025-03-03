#include <iostream>
#define SIZE 5
using namespace std;

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full!" << endl;
    } else {
        if (front == -1) front = 0;  
        queue[++rear] = value;
        cout << value << " added." << endl;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << queue[front++] << " removed." << endl;
        if (front > rear) front = rear = -1; // Reset when empty
    }
}

void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
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
