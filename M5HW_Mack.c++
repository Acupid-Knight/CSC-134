// M5HW
// MackA
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function for Question 1: Average Rainfall
void averageRainfall() {
    string month1, month2, month3;
    double rain1, rain2, rain3;

    cout << "Enter month: ";
    cin >> month1;
    cout << "Enter rainfall for " << month1 << ": ";
    cin >> rain1;

    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter rainfall for " << month2 << ": ";
    cin >> rain2;

    cout << "Enter month: ";
    cin >> month3;
    cout << "Enter rainfall for " << month3 << ": ";
    cin >> rain3;

    double average = (rain1 + rain2 + rain3) / 3.0;
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average << " inches." << endl;
}

// Function for Question 2: Volume of a Block
void blockVolume() {
    double width, length, height;

    cout << "Enter width: ";
    cin >> width;
    while (width <= 0) {
        cout << "Width must be greater than zero. Try again: ";
        cin >> width;
    }

    cout << "Enter length: ";
    cin >> length;
    while (length <= 0) {
        cout << "Length must be greater than zero. Try again: ";
        cin >> length;
    }

    cout << "Enter height: ";
    cin >> height;
    while (height <= 0) {
        cout << "Height must be greater than zero. Try again: ";
        cin >> height;
    }

    double volume = width * length * height;
    cout << "The volume of the block is " << volume << " cubic units." << endl;
}

// Function for Question 3: Roman Numeral Conversion
void romanNumeral() {
    int number;

    cout << "Enter a number (1 - 10): ";
    cin >> number;
    while (number < 1 || number > 10) {
        cout << "The number must be between 1 and 10. Try again: ";
        cin >> number;
    }

    cout << "The Roman numeral version of " << number << " is ";
    switch (number) {
        case 1: cout << "I"; break;
        case 2: cout << "II"; break;
        case 3: cout << "III"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VI"; break;
        case 7: cout << "VII"; break;
        case 8: cout << "VIII"; break;
        case 9: cout << "IX"; break;
        case 10: cout << "X"; break;
    }
    cout << "." << endl;
}

// Function for Question 4: Geometry Calculator
void geometryCalculator() {
    int choice;

    cout << "Geometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "The valid choices are 1 through 4. Try again: ";
        cin >> choice;
    }

    if (choice == 1) {
        double radius;
        cout << "Enter the circle's radius: ";
        cin >> radius;
        while (radius < 0) {
            cout << "The radius cannot be less than zero. Try again: ";
            cin >> radius;
        }
        double area = 3.14159 * radius * radius;
        cout << "The area is " << area << endl;
    } else if (choice == 2) {
        double length, width;
        cout << "Enter the length: ";
        cin >> length;
        while (length < 0) {
            cout << "The length cannot be less than zero. Try again: ";
            cin >> length;
        }
        cout << "Enter the width: ";
        cin >> width;
        while (width < 0) {
            cout << "The width cannot be less than zero. Try again: ";
            cin >> width;
        }
        double area = length * width;
        cout << "The area is " << area << endl;
    } else if (choice == 3) {
        double base, height;
        cout << "Enter the base: ";
        cin >> base;
        while (base < 0) {
            cout << "The base cannot be less than zero. Try again: ";
            cin >> base;
        }
        cout << "Enter the height: ";
        cin >> height;
        while (height < 0) {
            cout << "The height cannot be less than zero. Try again: ";
            cin >> height;
        }
        double area = 0.5 * base * height;
        cout << "The area is " << area << endl;
    } else {
        cout << "Exiting Geometry Calculator." << endl;
    }
}

// Function for Question 5: Distance Traveled
void distanceTraveled() {
    double speed, time;

    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    while (speed < 0) {
        cout << "Speed cannot be negative. Try again: ";
        cin >> speed;
    }

    cout << "How many hours has it traveled? ";
    cin >> time;
    while (time < 1) {
        cout << "Time must be at least 1 hour. Try again: ";
        cin >> time;
    }

    cout << "Hour\tDistance Traveled\n";
    cout << "-------------------------\n";
    for (int i = 1; i <= time; ++i) {
        cout << i << "\t" << speed * i << endl;
    }
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "Main Menu\n";
        cout << "1. Average Rainfall\n";
        cout << "2. Volume of a Block\n";
        cout << "3. Roman Numerals\n";
        cout << "4. Geometry Calculator\n";
        cout << "5. Distance Traveled\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: averageRainfall(); break;
            case 2: blockVolume(); break;
            case 3: romanNumeral(); break;
            case 4: geometryCalculator(); break;
            case 5: distanceTraveled(); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}

