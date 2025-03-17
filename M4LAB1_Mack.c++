//CSC 134
//M4LAB1_Mack  
//Antonio Mack Jr
//3/17/25

#include <iostream>
using namespace std;
  
int main() {
    // string pattern = "🍟 🌭;"
    string pattern = "😐 🥅 ";
    const int WIDTH = 8;
    const int HEIGHT = 5;
    
    // while loop version
    int count = 0;
    while(count < WIDTH) {
         cout  << pattern;
         count++;
    }
    cout << endl;

    // print a row (horizontal)
    cout << "row" << endl;
    for (int i=0; i < WIDTH; i++) {
        cout << pattern;
    }
    cout << endl;

    // print a column (vertical)
    cout << "column" << endl;
    for (int i=0; i < HEIGHT; i++) {
        cout << pattern << endl;
    }

    // print a square (combine both)
    // TODO: ask the clear
    int width, height;
    bool good_values = false;
    
    // ask for width and height until valid input is given
    do {
       cout << "Enter width and height, both >0" << endl;
       cin >> width >> height;
       if(width > 0 && height > 0) {
          good_values = true;
       }
       else {
           cout << "Width and height must be > 0" << endl;
       }
    } while (!good_values);  // Keep asking until valid input is given

    // Once valid input is given, print the square
    cout << "Square of " << width << " by " << height << endl;
    for (int v = 0; v < height; v++) {
        // print one row of the square
        for (int h = 0; h < width; h++) {
            cout << pattern;
        }
        cout << endl; // go to the next row
    }

    return 0;
}
