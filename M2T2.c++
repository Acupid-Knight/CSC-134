//CSC 134
//M2T2
//Antonio Mack Jr
//2/3/25


#include <iostream>
#include <iomanip>      // for the 2 decimal place trick
using namespace std;
  
int main()
{
   string store_name = "Mack's Burgers";
   string food_name = "Burger combo";
   int how_many;
   double food_price = 6.99; // $


   // Our receipt variables
   double subtotal, total;
   double tax_percent, tax_cost;

   // Do the order
   cout << "Welcome to the store " << store_name << " store!" << endl;
   cout << "You ordered one " << food_name << " and it's $" << food_price << endl;
   cout << "How many do you want? ";
   cin  >> how_many;
   
   // Calculate subtotal, tax, total
   tax_percent = 0.08; // assignment says &%, so 8/100 (as a double)
   subtotal = food_price * how_many;
   tax_cost = subtotal * tax_percent; // &% of 45.99
   total    = subtotal + tax_cost;
   // print the receipt
   // Tried two ways to line up : setw() and tab \t
   cout << setprecision(2) << fixed; // magic to turn on 2 decimals
   cout << food_name << " x " << how_many << endl; 
   cout << "-----------------------------------" << endl;
   cout << setw(12) << "Subtotal: \$" << setw(6) << subtotal << endl;
   cout << setw(12) << "Tax (&%): \$" << setw(6) << tax_cost << endl;
   cout << "-----------------------------------" << endl;
   cout << setw(12) << "Total:    \$" << setw(6) << total << endl;
   cout << "-----------------------------------" << endl;
   
   
   
   
   cout << "Have a nice day!" << endl;
   return 0;
}
