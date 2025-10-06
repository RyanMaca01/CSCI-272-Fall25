#include <iostream>
using namespace std;

int main() {
    int num = 10;      // a normal integer
    int* ptr = &num;   // pointer to num (stores the address of num)

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Pointer holds: " << ptr << endl;
    cout << "Value at pointer (dereference): " << *ptr << endl;

int arr[3] = {10, 20, 30};
    int* ptr = arr;   // arr is already a pointer to first element

    cout << "First element: " << *ptr << endl;
    cout << "Second element: " << *(ptr + 1) << endl;
    cout << "Third element: " << *(ptr + 2) << endl;



int var1 = 1;
int var2 = 3;

cout << "The address of var 1" << &var1 << endl;
cout << "The address of var 1" << &var2 << endl;


int var = 5;

// assign address of var to point_var
int* point_var = &var;


    return 0;
}