#include <iostream>
using namespace std;

 
struct Stack {
    int top;        
    int capacity;   
    int* arr;       

 
    void initialize(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  
    }

   // plaindrome check and decimal to binary 
    void destroy() {
        delete[] arr;
    }

 
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

 
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;   
        }
        int poppedValue = arr[top--];
        cout << poppedValue << " popped from stack." << endl;
        return poppedValue;
    }

   
    int peek() {
        if (top == -1) {
            cout << "Stack is empty! No top element." << endl;
            return -1;   
        }
        return arr[top];
    }

 
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack;
    stack.initialize(size);   

    int choice, value;
    while (true) {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                value = stack.peek();
                if (value != -1)
                    cout << "Top element is: " << value << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                stack.destroy();  
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
