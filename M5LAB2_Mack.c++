// M5LAB2
// MackA

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
double getLength(); 
double getArea(double length, double width);
double getWidth(); 
void displayData(double area); 

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length;    // The rectangle's length
   double width;     // The rectangle's width
   double area;      // The rectangle's area
          
   // move this into functions

   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
    displayData(area);
  
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************
 double getLength() {
  double length;
  cout << "Pick you number for length" << endl; 
  cin >> length;
  return length;
}

double getWidth() {
  double width; 
  cout << "Pick you number for width"  << endl;
  cin>> width; 
  return width;
}

double getArea(double length, double width)  {
  double area;
  area = length * width;  
  return area;
}
void displayData(double area) {
  cout << "area = " << area << endl;
}