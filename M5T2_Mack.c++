
 // CSC 134
 // MackA
 // 3/24/25

 #include <iostream>
 using namespace std;

// CSC 134
// M5T2
// name
// 3/24/2025

// TODO:
// add declarations
// finish the functions
// write main()

void print_line(int number, int square) {
    cout << number << ":" << square <<
    endl;
}


int growth(int number) {
    int square = number * number; 
     // 2 to power
     return square; 
}

int main() {
// Example: print sqaures from 1 to 10
for (int num=1; num<=10; num++) {
    int square = growth (num); // should call find_square()
    print_line(num, square);
  }
}
int find_square(int number) {
    return 0; // fix
}

