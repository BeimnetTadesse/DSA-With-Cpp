#include <iostream>
using namespace std;

int* arr;
int front = 0, rear = -1, queueSize = 0, capacity;

void enqueue(int value) {
    if (queueSize == capacity) {
        cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    queueSize++;
}

void dequeue() {
    if (queueSize == 0) {
        cout << "Queue is empty\n";
        return;
    }
    front = (front + 1) % capacity;
    queueSize--;
}

int peek() {
    if (queueSize == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

void display() {
    if (queueSize == 0) {
        cout << "Queue is empty\n";
        return;
    }
    int i = front;
    for (int count = 0; count < queueSize; count++) {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << endl;
}

int main() {
    int operation, value;

    cout << "Enter the capacity of the queue: ";
    cin >> capacity;
    arr = new int[capacity];

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter operation number: ";
        cin >> operation;

        switch (operation) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Peek: " << peek() << endl;
                break;
            case 4:
                cout << "Queue elements: ";
                display();
                break;
            case 5:
                cout << "Exiting program...\n";
                delete[] arr;
                return 0;
            default:
                cout << "Invalid operation. Try again.\n";
        }
    }

    return 0;
}
