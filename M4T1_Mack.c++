//CSC 134
//M4T1_Mack - 
//Antonio Mack Jr
//3/10/25


#include <iostream>
using namespace std;
  
int main()
{

    // Part 1, just count
    int count = 1;
    while (count < 5) {
        cout << "Hello number " << count << endl;
        // count = count + 1;
        // count += 1;
        count++; // all do the same thing
    }
    cout << "Finished!" << endl;
   // Lets right in into a file
   // part 2 - Table of Square
   // requires #include streams
   const int MIN_NUM = 1;
   const int MAX_NUM = 100;
   int num = MIN_NUM;
   unsigned long sq; // holds a much bigger number
   cout << endl << "Table of Squares" << endl;
   cout << "---------------" << endl;
   while (num <= MAX_NUM) {
      sq = num * num;
      cout << num << "/t" << sq << endl;
      num = num + 1;
   }
   // close the file
   return 0;
}