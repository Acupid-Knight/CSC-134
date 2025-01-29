//CSC 134
// M2T1
//Antonio Mack Jr
// 1/29/25


#include <iostream>
#include <iomanip>
using namespace std;
  
int main()
{
    // Declare your variables (boxes to hold data)
   string name = "Antonio";        // strings hold words, sentences, names, ...
   int num_apples = 100;           // int are whole numbers (no decimal)
   double price_each = 0.25;       // any number with a decimal is a double
   // new for this verison - empty until user types something.
   string customer_name;
   int apples_to_buy;

    // Say hi
    cout << "Hi, what's your name? ";
    cin >> customer_name;
    cout << "Nice to meet you, " << customer_name << endl;

   cout << "Welcome to the "<< "Mack" << " apple farm" << endl;
   cout << "We have " << num_apples << " apples in stock." << endl;  
   cout << "Price per apple is: $" << price_each << endl;
   cout << endl;
   
   // Calculate total
   double total_cost = num_apples * price_each;
   
   // print answer
   cout << fixed << setprecision(2); // this makes it print 25.00 instead of 25
   cout << "The total for all "<< num_apples << " is $" << total_cost << endl; 
   
   //Make a deal
   cout << "How many apples do you want? ";
   cin >> apples_to_buy; 
   double customer_cost = apples_to_buy * price_each;
   cout << "For " << apples_to_buy << " your total is $" << customer_cost << endl;

   return 0; // no errors

}
