#include <iostream>
using namespace std;

class Lsearch {
    int a[100], target, countValue; 
    int n; 
public:
    void accept();
    int search();
    void countOccurrences(); 
    void targetIndex();
};

void Lsearch::accept() {
    cout << "Enter total number of values: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Array elements:";
    for (int i = 0; i < n; i++) {
        cout << "\n" << a[i];
    }
    cout << endl;
}

int Lsearch::search() {
    cout << "Enter target value: ";
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

void Lsearch::countOccurrences() {
    int count = 0; // Local variable count
    cout << "Enter target value for count: ";
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            count++;
        }
    }
    cout << "The target value " << target << " occurs " << count << " times in the array." << endl;
}

void Lsearch::targetIndex() {
    int index = search();
    if (index != -1) {
        cout << "The target value is found at index " << index << "." << endl;
    } else {
        cout << "The target value is not found in the array." << endl;
    }
}

int main() {
    Lsearch L; 
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Accept array elements\n";
        cout << "2. Search for a value\n";
        cout << "3. Count occurrences of a value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                L.accept();
                break;
            case 2:
                L.targetIndex();
                break;
            case 3:
                L.countOccurrences(); 
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
