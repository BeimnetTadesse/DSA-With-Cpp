#include <iostream>
using namespace std;

struct Student {
    int data;
    Student* next;
};

Student* start = nullptr;

void insertAtBeginning(int value) {
    Student* newStudent = new Student();
    newStudent->data = value;
    newStudent->next = start;
    start = newStudent;
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtMiddle(int value, int position) {
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    Student* newStudent = new Student();
    newStudent->data = value;

    Student* temp = start;
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        delete newStudent;
    } else {
        newStudent->next = temp->next;
        temp->next = newStudent;
        cout << "Inserted " << value << " at position " << position << ".\n";
    }
}

void insertAtEnd(int value) {
    Student* newStudent = new Student();
    newStudent->data = value;
    newStudent->next = nullptr;

    if (start == nullptr) {
        start = newStudent;
    } else {
        Student* temp = start;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void deleteFirst() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Student* temp = start;
    start = start->next;
    delete temp;
    cout << "Deleted the first element.\n";
}

void deleteMiddle(int position) {
    if (position <= 0 || start == nullptr) {
        cout << "Invalid position or list is empty.\n";
        return;
    }

    Student* temp = start;
    Student* prev = nullptr;

    for (int i = 1; i < position && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
    } else {
        prev->next = temp->next;
        delete temp;
        cout << "Deleted element at position " << position << ".\n";
    }
}

void deleteLast() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (start->next == nullptr) {
        delete start;
        start = nullptr;
    } else {
        Student* temp = start;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Deleted the last element.\n";
}

int getValue(int position) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return -1;
    }

    Student* temp = start;
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        return -1;
    }
    return temp->data;
}

void displayForward() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List from first to last: ";
    Student* temp = start;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayBackwardHelper(Student* Student) {
    if (Student == nullptr) return;
    displayBackwardHelper(Student->next);
    cout << Student->data << " ";
}

void displayBackward() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List from last to first: ";
    displayBackwardHelper(start);
    cout << endl;
}
 


int main() {
    int mainChoice, insertChoice, deleteChoice, value, position;

    do {
        cout << "\nMain Menu:\n";
        cout << "1) Insert\n2) Delete\n3) Get Value\n4) Display\n5) Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;
        switch (mainChoice) {
            case 1: // Insert menu
                do {
                    cout << "\nInsert Menu:\n";
                    cout << "1) Insert at the beginning\n";
                    cout << "2) Insert somewhere in the middle\n";
                    cout << "3) Insert at the end\n";
                    cout << "4) Back\n";
                    cout << "Choose an option: ";
                    cin >> insertChoice;

                    switch (insertChoice) {
                        case 1:
                            cout << "Enter value to insert at the beginning: ";
                            cin >> value;
                            insertAtBeginning(value);
                            break;
                        case 2:
                            cout << "Enter value and position to insert in the middle: ";
                            cin >> value >> position;
                            insertAtMiddle(value, position);
                            break;
                        case 3:
                            cout << "Enter value to insert at the end: ";
                            cin >> value;
                            insertAtEnd(value);
                            break;
                    }
                } while (insertChoice != 4);
                break;

            case 2: // Delete menu
                do {
                    cout << "\nDelete Menu:\n";
                    cout << "1) Delete the first element\n";
                    cout << "2) Delete an element somewhere in the middle\n";
                    cout << "3) Delete the last element\n";
                    cout << "4) Back\n";
                    cout << "Choose an option: ";
                    cin >> deleteChoice;

                    switch (deleteChoice) {
                        case 1:
                            deleteFirst();
                            break;
                        case 2:
                            cout << "Enter position of element to delete in the middle: ";
                            cin >> position;
                            deleteMiddle(position);
                            break;
                        case 3:
                            deleteLast();
                            break;
                    }
                } while (deleteChoice != 4);
                break;

            case 3: // Get Value
                cout << "Enter position to get value: ";
                cin >> position;
                value = getValue(position);
                if (value != -1) {
                    cout << "Value at position " << position << " is " << value << ".\n";
                }
                break;

            case 4: // Display menu
                int displayChoice;
                cout << "\nDisplay Menu:\n";
                cout << "1) Display from first to last\n";
                cout << "2) Display from last to first\n";
                cout << "Choose an option: ";
                cin >> displayChoice;
                
                if (displayChoice == 1) {
                    displayForward();
                } else if (displayChoice == 2) {
                    displayBackward();
                } else {
                    cout << "Invalid choice.\n";
                }
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (mainChoice != 5);

    return 0;
}