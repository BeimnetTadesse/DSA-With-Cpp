#include <iostream>
using namespace std;

// Function prototypes
void displayMainMenu();
void displaySearchMenu();
void displaySortMenu();
void displayArray(int data[], int size);
void linearSearch(int data[], int size, int key);
void binarySearch(int data[], int size, int key);
void simpleSort(int data[], int size);
void bubbleSort(int data[], int size);
void insertionSort(int data[], int size);
void selectionSort(int data[], int size);
void binaryInsertionSort(int data[], int size);

int main() {
    int data[] = {34, 7, 23, 32, 5, 62};
    int size = sizeof(data) / sizeof(data[0]);
    int mainChoice, searchChoice, sortChoice, key;

    do {
        displayMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: // Search
                do {
                    displaySearchMenu();
                    cin >> searchChoice;

                    if (searchChoice == 1) {
                        cout << "Enter key to search (Linear): ";
                        cin >> key;
                        linearSearch(data, size, key);
                    } else if (searchChoice == 2) {
                        cout << "Enter key to search (Binary): ";
                        cin >> key;
                        binarySearch(data, size, key);
                    }
                } while (searchChoice != 3);
                break;

            case 2: // Sort
                do {
                    displaySortMenu();
                    cin >> sortChoice;

                    // Sort the array and display it
                    switch (sortChoice) {
                        case 1: simpleSort(data, size); break;
                        case 2: bubbleSort(data, size); break;
                        case 3: insertionSort(data, size); break;
                        case 4: selectionSort(data, size); break;
                        case 5: binaryInsertionSort(data, size); break;
                    }

                    if (sortChoice != 6) {
                        cout << "Sorted Array: ";
                        displayArray(data, size);
                    }
                } while (sortChoice != 6);
                break;

            case 3: // Exit
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option, try again.\n";
                break;
        }
    } while (mainChoice != 3);

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    cout << "\nMain Menu\n";
    cout << "1) Search\n";
    cout << "2) Sort\n";
    cout << "3) Exit\n";
    cout << "Choose an option: ";
}

// Function to display the search menu
void displaySearchMenu() {
    cout << "\nSearch Menu\n";
    cout << "1) Linear Search\n";
    cout << "2) Binary Search\n";
    cout << "3) Back\n";
    cout << "Choose an option: ";
}

// Function to display the sort menu
void displaySortMenu() {
    cout << "\nSort Menu\n";
    cout << "1) Simple Sort\n";
    cout << "2) Bubble Sort\n";
    cout << "3) Insertion Sort\n";
    cout << "4) Selection Sort\n";
    cout << "5) Binary Insertion Sort\n";
    cout << "6) Back\n";
    cout << "Choose an option: ";
}

// Function to display the array
void displayArray(int data[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

// Linear Search function
void linearSearch(int data[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == key) {
            cout << "Key found at index " << i << "\n";
            return;
        }
    }
    cout << "Key not found.\n";
}

// Binary Search function
void binarySearch(int data[], int size, int key) {
    int sortedData[size];
    for (int i = 0; i < size; ++i) sortedData[i] = data[i];
    simpleSort(sortedData, size); // Sort before binary search
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sortedData[mid] == key) {
            cout << "Key found at index " << mid << " in the sorted array.\n";
            return;
        } else if (sortedData[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Key not found.\n";
}

// Simple Sort function
void simpleSort(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (data[i] > data[j]) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    cout << "Array sorted using Simple Sort.\n";
}

// Bubble Sort function
void bubbleSort(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted using Bubble Sort.\n";
}

// Insertion Sort function
void insertionSort(int data[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
    cout << "Array sorted using Insertion Sort.\n";
}

// Selection Sort function
void selectionSort(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
    cout << "Array sorted using Selection Sort.\n";
}

// Binary Insertion Sort function
void binaryInsertionSort(int data[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = data[i];
        int left = 0, right = i;

        // Binary search for the correct position of data[i]
        while (left < right) {
            int mid = (left + right) / 2;
            if (key >= data[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        for (int j = i; j > left; --j) {
            data[j] = data[j - 1];
        }
        data[left] = key;
    }
    cout << "Array sorted using Binary Insertion Sort.\n";
}