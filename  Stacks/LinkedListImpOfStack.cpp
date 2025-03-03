#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top;

    Stack()
    {
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack." << endl;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped from stack." << endl;
        return poppedValue;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty! No top element." << endl;
            return -1;
        }
        return top->data;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack stack;

    int choice, value;
    while (true)
    {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
