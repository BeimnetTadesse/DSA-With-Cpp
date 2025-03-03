#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    int stack[100];
    int top = -1;

    while (n > 0) {
        stack[++top] = n % 2;
        n /= 2;
    }

    cout << "Binary: ";
    while (top >= 0) {
        cout << stack[top--];
    }
    cout << endl;
}

int main() {
 char choice;
    do {
        int n;
        cout << "Enter a decimal number: ";
        cin >> n;
        if (n >= 0) {
            decimalToBinary(n);
        } else {
            cout << "Please enter a non-negative number." << endl;
        }
        cout << "Do you want to convert another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}