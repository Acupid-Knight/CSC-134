//CSC 134
// M1HW1
//Antonio Mack Jr
// 1/29/25


#include <iostream>
#include <iomanip>
using namespace std;
  
int main()
{
    // Declare your variables (boxes to hold data)
   string movie_name = "Avatar";        // strings hold words, sentences, names, ...
   string director = "James Cameron";    // int are whole numbers (no decimal)
   double box_office = 2.923;   // any number with a decimal is a double

   // output
   cout << "The movie is called "<< movie_name << "." << endl;
   cout << "The director is " << director << "." << endl;  
   cout << "Box office was $" << box_office << " billion." << endl;
   
   // Movie quote
   cout << "       Movie quote" << endl; 
   cout << "“If not us, then who?” – Teo." << endl; 
   cout << "Jake Sully : “I was a warrior who dreamed he could bring peace. Sooner or later, though, you always wake up.“" << endl; 
   
   return 0; // no errors

}
