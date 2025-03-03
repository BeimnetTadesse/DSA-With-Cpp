#include <iostream>
using namespace std;

struct Student {
    int data;
    Student *next;
    Student *prev;
};

Student *start = nullptr;

 
void insertAtBeginning(int value) {
    Student *newStudent = new Student();
    newStudent->data = value;

    if (start == nullptr) {
        newStudent->next = newStudent;
        newStudent->prev = newStudent;
        start = newStudent;
    } else {
        Student *last = start->prev;

        newStudent->next = start;
        newStudent->prev = last;

        start->prev = newStudent;
        last->next = newStudent;

        start = newStudent;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

 
void insertAtEnd(int value) {
    Student *newStudent = new Student();
    newStudent->data = value;

    if (start == nullptr) {
        newStudent->next = newStudent;
        newStudent->prev = newStudent;
        start = newStudent;
    } else {
        Student *last = start->prev;

        newStudent->next = start;
        newStudent->prev = last;

        last->next = newStudent;
        start->prev = newStudent;
    }
    cout << "Inserted " << value << " at the end.\n";
}

 
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Student *newStudent = new Student();
    newStudent->data = value;

    Student *temp = start;
    int count = 1;

    while (count < position - 1 && temp->next != start) {
        temp = temp->next;
        count++;
    }

    if (count < position - 1) {
        cout << "Position out of bounds. Insertion failed.\n";
        delete newStudent;
        return;
    }

    newStudent->next = temp->next;
    newStudent->prev = temp;

    temp->next->prev = newStudent;
    temp->next = newStudent;

    cout << "Inserted " << value << " at position " << position << ".\n";
}

// Delete the first element
void deleteFirst() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (start->next == start) {
        delete start;
        start = nullptr;
    } else {
        Student *last = start->prev;
        Student *temp = start;

        start = start->next;
        start->prev = last;
        last->next = start;

        delete temp;
    }
    cout << "Deleted the first element.\n";
}

// Delete the last element
void deleteLast() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (start->next == start) {
        delete start;
        start = nullptr;
    } else {
        Student *last = start->prev;
        last->prev->next = start;
        start->prev = last->prev;

        delete last;
    }
    cout << "Deleted the last element.\n";
}

// Delete at a specific position
void deleteAtPosition(int position) {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (position == 1) {
        deleteFirst();
        return;
    }

    Student *temp = start;
    int count = 1;

    while (count < position && temp->next != start) {
        temp = temp->next;
        count++;
    }

    if (count < position) {
        cout << "Position out of bounds. Deletion failed.\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    cout << "Deleted element at position " << position << ".\n";
}

// Display list from first to last
void displayForward() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List from first to last: ";
    Student *temp = start;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

// Display list from last to first
void displayBackward() {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "List from last to first: ";
    Student *temp = start->prev;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != start->prev);
    cout << endl;
}

// Get value at a specific position
void getValueAtPosition(int position) {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Student *temp = start;
    int count = 1;

    while (count < position && temp->next != start) {
        temp = temp->next;
        count++;
    }

    if (count < position) {
        cout << "Position out of bounds. Cannot retrieve value.\n";
        return;
    }

    cout << "Value at position " << position << " is: " << temp->data << endl;
}

// Main program
int main() {
    int mainChoice, insertChoice, deleteChoice, displayChoice, value, position;

    do {
        cout << "\nMain Menu:\n";
        cout << "1) Insert\n2) Delete\n3) Display\n4) Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            do {
                cout << "\nInsert Menu:\n";
                cout << "1) Insert at the beginning\n";
                cout << "2) Insert at the end\n";
                cout << "3) Insert at a specific position\n";
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
                    cout << "Enter value to insert at the end: ";
                    cin >> value;
                    insertAtEnd(value);
                    break;
                case 3:
                    cout << "Enter value to insert: ";
                    cin >> value;
                    cout << "Enter position to insert: ";
                    cin >> position;
                    insertAtPosition(value, position);
                    break;
                }
            } while (insertChoice != 4);
            break;

        case 2:
            do {
                cout << "\nDelete Menu:\n";
                cout << "1) Delete the first element\n";
                cout << "2) Delete the last element\n";
                cout << "3) Delete at a specific position\n";
                cout << "4) Back\n";
                cout << "Choose an option: ";
                cin >> deleteChoice;

                switch (deleteChoice) {
                case 1:
                    deleteFirst();
                    break;
                case 2:
                    deleteLast();
                    break;
                case 3:
                    cout << "Enter position to delete: ";
                    cin >> position;
                    deleteAtPosition(position);
                    break;
                }
            } while (deleteChoice != 4);
            break;

        case 3:
            cout << "\nDisplay Menu:\n";
            cout << "1) Display from first to last\n";
            cout << "2) Display from last to first\n";
            cout << "Choose an option: ";
            cin >> displayChoice;

            if (displayChoice == 1) {
                displayForward();
            } else if (displayChoice == 2) {
                displayBackward();
            } else
                cout << "Invalid choice.\n";
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (mainChoice != 4);

    return 0;
}
