#include <iostream>
using namespace std;
// delete leaf , one child , two child 
// delete by merging(2 types ) and copying (2 types) // display 4 values 

// finding the  level 
// finding height
// searching
struct Person {
    string name;
    int age;
};
int queueSize = 0, capacity;
Person* arr; 

void enqueue(Person person) {
    if (queueSize == capacity) {
        cout << "Priority Queue is full\n";
        return;
    }
  
    arr[queueSize] = person;
    queueSize++;
    
   
    int i = queueSize - 1;
    while (i > 0 && arr[i].age > arr[(i - 1) / 2].age) {
      
        Person temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void dequeue() {
    if (queueSize == 0) {
        cout << "Priority Queue is empty\n";
        return;
    }
    
    cout << "Dequeued: " << arr[0].name << " (" << arr[0].age << ")\n";
    
  
    arr[0] = arr[queueSize - 1];
    queueSize--;
    
    
    int i = 0;
    while (i * 2 + 1 < queueSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < queueSize && arr[left].age > arr[largest].age)
            largest = left;
        if (right < queueSize && arr[right].age > arr[largest].age)
            largest = right;

        if (largest != i) {
           
            Person temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

Person peek() {
    if (queueSize == 0) {
        cout << "Priority Queue is empty\n";
        Person emptyPerson = {"", -1};
        return emptyPerson;
    }
    return arr[0];
}

void display() {
    if (queueSize == 0) {
        cout << "Priority Queue is empty\n";
        return;
    }
    
    cout << "Priority Queue elements: \n";
    for (int i = 0; i < queueSize; i++) {
        cout << arr[i].name << " (" << arr[i].age << ")\n";
    }
}

int main() {
    int operation;
    Person person;

    cout << "Enter the capacity of the priority queue: ";
    cin >> capacity;
    arr = new Person[capacity];

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
                cout << "Enter name: ";
                cin >> person.name;
                cout << "Enter age: ";
                cin >> person.age;
                enqueue(person);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                person = peek();
                if (person.age != -1)
                    cout << "Peek: " << person.name << " (" << person.age << ")\n";
                break;
            case 4:
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
