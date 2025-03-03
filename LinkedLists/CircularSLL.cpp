#include <iostream>
using namespace std;

struct Student
{
    int data;
    Student *next;
};

Student *start = nullptr;

void insertAtBeginning(int value)
{
    Student *newStudent = new Student();
    newStudent->data = value;

    if (start == nullptr)
    {
        start = newStudent;
        newStudent->next = start; // Circular link to itself
    }
    else
    {
        Student *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = start;
        start = newStudent;
    }
    cout << "Inserted " << value << " at the beginning.\n";
}

void insertAtEnd(int value)
{
    Student *newStudent = new Student();
    newStudent->data = value;

    if (start == nullptr)
    {
        start = newStudent;
        newStudent->next = start; // Circular link to itself
    }
    else
    {
        Student *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = start;
    }
    cout << "Inserted " << value << " at the end.\n";
}

void insertAtPosition(int value, int position)
{
    Student *newStudent = new Student();
    newStudent->data = value;

    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }

    Student *temp = start;
    int count = 1;

    while (temp->next != start && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (count < position - 1)
    {
        cout << "Position out of bounds. Insertion failed.\n";
        delete newStudent;
        return;
    }

    newStudent->next = temp->next;
    temp->next = newStudent;

    cout << "Inserted " << value << " at position " << position << ".\n";
}

void deleteFirst()
{
    if (start == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (start->next == start)
    {
        delete start;
        start = nullptr;
    }
    else
    {
        Student *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = start->next;
        delete start;
        start = temp->next;
    }
    cout << "Deleted the first element.\n";
}

void deleteLast()
{
    if (start == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (start->next == start)
    {
        delete start;
        start = nullptr;
    }
    else
    {
        Student *temp = start;
        while (temp->next->next != start)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = start;
    }
    cout << "Deleted the last element.\n";
}

void deleteAtPosition(int position)
{
    if (start == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position == 1)
    {
        deleteFirst();
        return;
    }

    Student *temp = start;
    int count = 1;

    while (temp->next != start && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == start || count < position - 1)
    {
        cout << "Position out of bounds. Deletion failed.\n";
        return;
    }

    Student *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    cout << "Deleted element at position " << position << ".\n";
}

void displayForward()
{
    if (start == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    cout << "List from first to last: ";
    Student *temp = start;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}

void displayBackward()
{
    if (start == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    // Count the number of nodes in the list
    int count = 0;
    Student *temp = start;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != start);

    // Use the count to iterate in reverse order
    cout << "List from last to first: ";
    for (int i = count; i > 0; i--)
    {
        temp = start;

        // Move to the (i-1)th node
        for (int j = 1; j < i; j++)
        {
            temp = temp->next;
        }

        // Print the data of the current node
        cout << temp->data << " ";
    }
    cout << endl;
}

void getValueAtPosition(int position) {
    if (start == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Student* temp = start;
    int count = 1;

    // Traverse the list until the desired position
    while (temp->next != start && count < position) {
        temp = temp->next;
        count++;
    }

    // Check if the position is out of bounds
    if (count < position) {
        cout << "Position out of bounds. Cannot retrieve value.\n";
        return;
    }

    // Display the value at the position
    cout << "Value at position " << position << " is: " << temp->data << endl;
}


int main()
{
    int mainChoice, insertChoice, deleteChoice, displayChoice, value, position;

    do
    {
        cout << "\nMain Menu:\n";
        cout << "1) Insert\n2) Delete\n3) Display\n4) Get Value\n5) Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            do
            {
                cout << "\nInsert Menu:\n";
                cout << "1) Insert at the beginning\n";
                cout << "2) Insert at the end\n";
                cout << "3) Insert at a specific position\n";
                cout<< "4) Back\n";
                cout << "Choose an option: ";
                cin >> insertChoice;

                switch (insertChoice)
                {
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
            } while (insertChoice != 5);
            break;

        case 2:
            do
            {
                cout << "\nDelete Menu:\n";
                cout << "1) Delete the first element\n";
                cout << "2) Delete the last element\n";
                cout << "3) Delete at a specific position\n";
                cout << "4) Back\n";
                cout << "Choose an option: ";
                cin >> deleteChoice;

                switch (deleteChoice)
                {
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

            if (displayChoice == 1)
            {
                displayForward();
            }
            else if (displayChoice == 2)
            {
                displayBackward();
            }
            else
                cout << "Invalid choice.\n";
            break;

  case 4:
                    // Get value at a specific position
                    cout << "Enter position to get value: ";
                    cin >> position;
                    getValueAtPosition(position);
                    break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (mainChoice != 4);

    return 0;
}
