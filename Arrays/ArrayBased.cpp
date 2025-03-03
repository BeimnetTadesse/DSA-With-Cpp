#include <iostream>
using namespace std;

struct Array {
    int elements[100];
    int size;
};

// Function prototypes
void displayMenu();
void displayArray(const Array& arr);
void insertAtBeginning(Array& arr, int value);
void insertAtMiddle(Array& arr, int value, int position);
void insertAtEnd(Array& arr, int value);
void deleteFirstElement(Array& arr);
void deleteMiddleElement(Array& arr, int position);
void deleteLastElement(Array& arr);

int main() {
    Array arr;
    arr.size = 0;
    int choice, value, position;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert Menu
                cout << "\nInsert Menu\n";
                cout << "1. Insert at the beginning\n";
                cout << "2. Insert somewhere in the middle\n";
                cout << "3. Insert at the end\n";
                cout << "4. Back\n";
                cout << "Choose an option: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "Enter value to insert at the beginning: ";
                    cin >> value;
                    insertAtBeginning(arr, value);
                } else if (choice == 2) {
                    if (arr.size <= 1) {
                        cout << "Not enough elements for middle insertion.\n";
                    } else {
                        cout << "Enter value to insert in the middle: ";
                        cin >> value;
                        cout << "Enter position (1 to " << arr.size - 1 << "): ";
                        cin >> position;
                        insertAtMiddle(arr, value, position);
                    }
                } else if (choice == 3) {
                    cout << "Enter value to insert at the end: ";
                    cin >> value;
                    insertAtEnd(arr, value);
                } else {
                    cout << "Returning to main menu.\n";
                }
                break;

            case 2: // Delete Menu
                cout << "\nDelete Menu\n";
                cout << "1. Delete the first element\n";
                cout << "2. Delete an element somewhere in the middle\n";
                cout << "3. Delete the last element\n";
                cout << "4. Back\n";
                cout << "Choose an option: ";
                cin >> choice;

                if (choice == 1) {
                    deleteFirstElement(arr);
                } else if (choice == 2) {
                    if (arr.size <= 1) {
                        cout << "Not enough elements for middle deletion.\n";
                    } else {
                        cout << "Enter position (1 to " << arr.size - 1 << "): ";
                        cin >> position;
                        deleteMiddleElement(arr, position);
                    }
                } else if (choice == 3) {
                    deleteLastElement(arr);
                } else {
                    cout << "Returning to main menu.\n";
                }
                break;

            case 3: // Get Value
                cout << "Enter position to get value (0 to " << arr.size - 1 << "): ";
                cin >> position;
                if (position >= 0 && position < arr.size) {
                    cout << "Value at position " << position << ": " << arr.elements[position] << endl;
                } else {
                    cout << "Invalid position!\n";
                }
                break;

            case 4: // Display Array
                displayArray(arr);
                break;

            case 5: // Exit
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}

// Display main menu
void displayMenu() {
    cout << "\nMain Menu\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Get Value\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
}
// Display array contents
void displayArray(const Array& arr) {
    if (arr.size == 0) {
        cout << "Array is empty.\n";
    } else {
        cout << "Array elements: ";
        for (int i = 0; i < arr.size; i++) {
            cout << arr.elements[i] << " ";
        }
        cout << endl;
    }
}

// Insert at the beginning
void insertAtBeginning(Array& arr, int value) {
    if (arr.size < 100) {
        for (int i = arr.size; i > 0; i--) {
            arr.elements[i] = arr.elements[i - 1];
        }
        arr.elements[0] = value;
        arr.size++;
    } else {
        cout << "Array is full, cannot insert!\n";
    }
}

// Insert in the middle
void insertAtMiddle(Array& arr, int value, int position) {
    if (position > 0 && position < arr.size && arr.size < 100) {
        for (int i = arr.size; i > position; i--) {
            arr.elements[i] = arr.elements[i - 1];
        }
        arr.elements[position] = value;
        arr.size++;
    } else {
        cout << "Invalid position for middle insertion!\n";
    }
}

// Insert at the end
void insertAtEnd(Array& arr, int value) {
    if (arr.size < 100) {
        arr.elements[arr.size] = value;
        arr.size++;
    } else {
        cout << "Array is full, cannot insert!\n";
    }
}
//Deletion
// Delete the first element
void deleteFirstElement(Array& arr) {
    if (arr.size > 0) {
        for (int i = 0; i < arr.size - 1; i++) {
            arr.elements[i] = arr.elements[i + 1];
        }
        arr.size--;
    } else {
        cout << "Array is empty, cannot delete!\n";
    }
}

// Delete an element in the middle
void deleteMiddleElement(Array& arr, int position) {
    if (position > 0 && position < arr.size - 1) {
        for (int i = position; i < arr.size - 1; i++) {
            arr.elements[i] = arr.elements[i + 1];
        }
        arr.size--;
    } else {
        cout << "Invalid position for middle deletion!\n";
    }
}

// Delete the last element
void deleteLastElement(Array& arr) {
    if (arr.size > 0) {
        arr.size--;
    } else {
        cout << "Array is empty, cannot delete!\n";
    }
}