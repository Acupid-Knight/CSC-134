//CSC 134
//M3T2_Mack - Starting point
//Antonio Mack Jr
//2/24/25

#include <iostream>
// for random
#include <cmath>    
#include <ctime>
using namespace std;

int main() {
    const int SIDES = 6; // yours will differ!
    const int TO_HIT = 7;

    //int seed = 43;
    int seed = time(0);
    //cout << "seed is:" << seed << endl;
    // seed the random number generator
    srand(seed);
    // rand() is a large number, so we take the remainder which is %
    int roll1;
    // roll a few times
    roll1 = ( (rand() % SIDES)+1 );
    cout << roll1 << endl;
    int roll2;
    roll2 = ( (rand() % SIDES)+1 );
    cout << roll2 << endl;
    int total = 12; 
    total = roll1 + roll2;
    cout << "You rolled " << roll1 << " + " << roll2 << " = " << total << endl;

    if(total >= TO_HIT) {
       cout << "It's a hit!" << endl;
    }
    else{
        cout << "You missed :(" << endl; 
    }
  
  }