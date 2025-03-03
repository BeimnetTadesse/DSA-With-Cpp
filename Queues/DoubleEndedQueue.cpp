#include <iostream>
using namespace std;

int* arr;
int front = -1, rear = -1, dequeSize = 0, capacity;

void enqueueFront(int value) {
    if (dequeSize == capacity) {
        cout << "Deque is full\n";
        return;
    }
    if (front == -1) { // If deque is empty
        front = rear = 0;
    } else {
        front = (front - 1 + capacity) % capacity; // Wrap around to the end
    }
    arr[front] = value;
    dequeSize++;
}

void enqueueRear(int value) {
    if (dequeSize == capacity) {
        cout << "Deque is full\n";
        return;
    }
    if (rear == -1) { // If deque is empty
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    arr[rear] = value;
    dequeSize++;
}

void dequeueFront() {
    if (dequeSize == 0) {
        cout << "Deque is empty\n";
        return;
    }
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    dequeSize--;
}

void dequeueRear() {
    if (dequeSize == 0) {
        cout << "Deque is empty\n";
        return;
    }
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity; // Wrap around to the front
    }
    dequeSize--;
}

int peekFront() {
    if (dequeSize == 0) {
        cout << "Deque is empty\n";
        return -1;
    }
    return arr[front];
}

int peekRear() {
    if (dequeSize == 0) {
        cout << "Deque is empty\n";
        return -1;
    }
    return arr[rear];
}

void display() {
    if (dequeSize == 0) {
        cout << "Deque is empty\n";
        return;
    }
    int i = front;
    for (int count = 0; count < dequeSize; count++) {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << endl;
}

int main() {
    int operation, value;

    cout << "Enter the capacity of the deque: ";
    cin >> capacity;
    arr = new int[capacity];

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Peek Front\n";
        cout << "6. Peek Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter operation number: ";
        cin >> operation;

        switch (operation) {
            case 1:
                cout << "Enter value to enqueue at the front: ";
                cin >> value;
                enqueueFront(value);
                break;
            case 2:
                cout << "Enter value to enqueue at the rear: ";
                cin >> value;
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                cout << "Peek Front: " << peekFront() << endl;
                break;
            case 6:
                cout << "Peek Rear: " << peekRear() << endl;
                break;
            case 7:
                cout << "Deque elements: ";
                display();
                break;
            case 8:
                cout << "Exiting program...\n";
                delete[] arr;
                return 0;
            default:
                cout << "Invalid operation. Try again.\n";
        }
    }

    return 0;
}
