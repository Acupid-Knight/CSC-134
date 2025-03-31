
#include <iostream>
using namespace std;

/*
CSC 134
M5LAB1 - Choose Your Own Adventure
MackA
3/26/25
This template serves as a starting point
for your own program. We'll be using
void functions to tell a simple story,
where the user gets to make choices.

You can fork this template by clicking on the name above, then click the three
dots on the top right, and click 'fork repl'. This makes a copy for you to use.
*/

// Function Prototypes
// Any functions you make will need to
// be listed here, in this format, at the top.
// This is so the compiler knows to save
// room for them in the final program.
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_enter_back_door();
void choice_you_hide_under_the_stairwell();
void choice_come_front_these_steps();
void choice_leave_through_back_door();
void choice_leave_under_the_stairwell(); 
void choice_stay_under_the_stair();
void choice_leave_to_go_up_stair();
void choice_explore_down_stair();
void choice_investigate_where_he_went(); 
int get_choice(int size); 
// TODO: add more choices here

int main() {
  cout << "Theif" << endl;
  // load up the main menu
  main_menu();
  // when we return here, we're done
  cout << "Thanks for playing!" << endl;
  return 0; // finished with no errors
}

void main_menu() {
  // Write a simple menu that lets the user choose 1,2, or 3, or 4 to quit.
  cout << "Main Menu" << endl;
  cout << "You're in front of a spooky old house..." << endl;
  cout << "Do you:" << endl;
  cout << "1. Try the front door" << endl;
  cout << "2. Sneak around back" << endl;
  cout << "3. Forget it, and go home" << endl;
  cout << "4. [Quit]" << endl;
  cout << "Choose: ";
  int choice;
  cin >> choice;
  if (1 == choice) {
    choice_front_door();
  } else if (2 == choice) {
    choice_back_door();
  } else if (3 == choice) {
    choice_front_door();
  } else if (4 == choice) {
    cout << "Ok, quitting game" << endl;
    return; // go back to main()
  } else {
    cout << "That's not a valid choice, please try again." << endl;
    cin.ignore(); // clear the user input
    main_menu();  // try again
  }
}

// FUNCTION DEFINITIONS
// OK, we have the prototypes at the top, but
// now we have to actually write the functions.
// They go here, after main().
void choice_front_door() {
  cout << "Try the front door." << endl;
  cout << "It's locked. " << endl;
  cout << "Do you:" << endl;
  cout << "1. Check around back" << endl;
  cout << "2. Give up and go home" << endl;
  int choice;
  cout << "Choose: ";
  cin >> choice;
  if (1 == choice) {
    choice_back_door();
  } else if (2 == choice) {
    // choice_go_home();
  }
}

void choice_back_door() {
cout << "It's unlock." << endl; 
cout << "1. Enter the door" << endl;
cout << "2. Back out" << endl;
int choice; 
cout << "Choose: ";
cin >> choice; 
if (1 == choice) {
  choice_enter_back_door();
  } else if (2 == choice) {
    // choice_go_home();
  }
}
 
void choice_enter_back_door() {
cout << "You enter the mysterious home." << endl;
cout << "Where you find shatter glass and dried up blood." << endl;
cout << "As you walk through, you noticed the horrible smell." << endl;
cout << "Then, you here the door slame behind, which causes you to SCREAM!" << endl;
cout << "As you scream you here heavy footstep coming down the stair... " << endl;
cout << "1. You hide under the stairwell" << endl; 
cout << "2. You come front these footsteps" << endl;
cout << "3. You try to leave through the back-door" << endl;
int choice;
cout << "Choose: ";
cin >> choice;
if ( 1 == choice) {
  choice_you_hide_under_the_stairwell();
 }  else if (2 == choice) {
  choice_come_front_these_steps();
 }  else if (3 == choice) {
  choice_leave_through_back_door();
 }
}
  
void choice_come_front_these_steps(){
cout << "As you come front the person, you find a huge man with a chainsaw" << endl;
cout << "Luckyly fot you, he hasn't see you yet" << endl;
cout << "You go hide under the stairwell, where he walks pass you" << endl; 
cout << "1. Stay still!" << endl;
cout << "2. Leave the stairwell" << endl;
int choice;
choice = get_choice (2);
if ( 1== choice) {
   choice_stay_under_the_stair();   
}   else if (2 == choice) {
 choice_leave_under_the_stairwell();
 }
}

void choice_leave_through_back_door(){

}
void choice_you_hide_under_the_stairwell() {
cout << "As you hide under the stair, the man goes out the back door to try to find you." << endl;
cout << "When he goes out the back-door, you leave spot to explore." << endl;
cout << "1. Investigate where the man went" << endl;
cout << "2. leave spot to go up stair to explore" << endl;
cout << "3. leve spot to explore downstairs" << endl; 
int choice;
choice = get_choice (2);
if ( 1== choice) {
   choice_investigate_where_he_went();
} else if (2 == choice) {
     choice_explore_down_stair();
 } else if ( 3 == choice) { 
     choice_leave_to_go_up_stair();
   }
  }

void choice_leave_under_the_stairwell() { 

}
void choice_stay_under_the_stair() {

}

void choice_leave_to_go_up_stair() {

}
void choice_explore_down_stair() {

}
void choice_investigate_where_he_went() {

} 



int get_choice(int size) {
  // Only allow choices between 1 and size
  int numeric_limits; 
  int choice=0;
  while (choice < 1 || choice > size) {
    cout << "Choose: ";
    cin >> choice;
        // Check if the input is valid
        if (cin.fail()) {
          cin.clear(); // Clear the error flag
          cin.ignore(99999, '\n'); // Discard invalid input
          cout << "Invalid input. Please enter a number between 1 and " << size << "." << endl;
        }
  }
  cout << "You picked option #" << choice << endl;
  return choice;
}