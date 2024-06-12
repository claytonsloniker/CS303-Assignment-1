//CS303 Assignment 1
//Name: Clayton Sloniker

#include "Functions.h"

int main()
{
    int digits[150];
    int arraySize = 100; //tracks total values in array
    

    try {
        readFile(digits);

        // user menu
        while (true) {
            int choice, i, newValue, index, num;

            cout << string(25, '-') << endl;
            cout << "\tMAIN MENU\n\n";
            cout << "1. Search for a value" << endl;
            cout << "2. Modify a value" << endl;
            cout << "3. Add a new value to the end" << endl;
            cout << "4. Remove value" << endl;
            cout << "5. Print array" << endl;
            cout << "6. Exit" << endl;

            cout << "\nPlease enter your choice: ";
            cin >> choice;
            cout << endl;

            switch (choice) {
            case 1:
				cout << "Enter a number to search for: ";
				cin >> num;
                index = digitSearch(num, digits, arraySize);

                //output value
                if (index == -1) {
					cout << "The number was not found." << endl;
				}
                else {
					cout << "The number is at position " << index << endl;
				}
                cout << endl;
				break;
            case 2:
				cout << "Enter the index to modify: ";
				cin >> i;
				cout << "Enter the new value: ";
				cin >> newValue;
				modifyIndex(digits, arraySize, i, newValue);
				break;
            case 3:
                cout << "Enter the new value to add: ";
                cin >> newValue;
                addToEnd(digits, arraySize, newValue);
                cout << endl;
                break;
            case 4:
                cout << "Enter the index to remove: ";
				cin >> i;
				setIndexToZero(digits, arraySize, i);
				cout << endl;
				break;
            case 5:
                printArray(digits, arraySize);
                cout << endl;
                break;
            case 6:
                cout << "Thank you. Goodbye." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
				break;
            }
            
                
        }
    }
    catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
        cout << "Exiting Program..." << endl;
		return 1;
	}

	return 0;

}

void readFile(int digits[]) {
    string line, tempStr;
    int i = 0;
    ifstream inFS;


    //open input file
    cout << "Opening file A1input.txt..." << endl;
    inFS.open("A1input.txt");

    if (!inFS.is_open()) {
        throw runtime_error("Could not open file A1input.txt");
    }

    //read input file
    while (getline(inFS, line)) {
        istringstream inSS(line);
        while (getline(inSS, tempStr, ' ')) {
            digits[i] = stoi(tempStr);
            i++;
        }
    }
    cout << "File read successfully...\n\n";

    inFS.close();
}

int digitSearch(int num, int digits[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (digits[i] == num) {
            return i;
        }
    }

    return -1;
}

void modifyIndex(int digits[], int arraySize, int i, int newValue) {
    if (i < arraySize) {
        int oldValue = digits[i];
        digits[i] = newValue;
        cout << "Old value: " << oldValue << endl;
        cout << "New value: " << digits[i] << endl;
        cout << endl;
    }
    else {
		throw runtime_error("Index does not exist. Cannot modify value.");
	}
    
}

void addToEnd(int digits[], int &arraySize, int newValue) {
    if (arraySize < 150) {
		digits[arraySize] = newValue;
		arraySize++;
        cout << newValue << " added to the end of the array." << endl;
	}
    else {
		throw runtime_error("Array is full. Cannot add new value.");
	}
}

void setIndexToZero(int digits[], int& arraySize, int i) {
    if (i < arraySize) {
        digits[i] = 0;
        cout << "Index " << i << " set to 0." << endl;
        return;
    }
    cout << "Index does not exist. Cannot set value to 0." << endl;
}

void printArray(int digits[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << digits[i] << " ";
    }
}

