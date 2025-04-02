//CSC 134
//M4HW_Mack - 
//Antonio Mack Jr
//3/10/25


#include <iostream>
using namespace std;

int main() {
    int number;
    
    // Input validation loop
    do {
        cout << "Enter a number between 1 and 12: ";
        cin >> number;

        if (number < 1 || number > 12) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (number < 1 || number > 12);

    // Times table loop
    for (int i = 1; i <= 12; i++) {
        cout << number << " times " << i << " is " << number * i << "." << endl;
    }

    return 0;
}

