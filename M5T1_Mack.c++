
 // CSC 134
 // MackA
 // 3/24/25

 #include <iostream>
 using namespace std;

void say_hi();
int add(int first, int second);
void print_number(int num);
int global_x = 999; // global variable

int main() {
    int my_num = 99;
    cout << "in main,() my_num = " << my_num << endl; 
    cout << "global_x = " << global_x << endl;
    global_x ++; 
    say_hi(); 
    cout << "2 + 2 = ";
    int num = add(2, 2);
    print_number(num);

}
// Function define (full thing)
// Void fumction == just call ot, no return
void say_hi() {
    cout << "Hi" << endl;
}
// Value returning function
int add(int first, int second) {
    int answer = first + second;
    return answer;
}
// void, but takes a value (parameter)
void print_number(int num) {
     cout << num << endl; 
}
