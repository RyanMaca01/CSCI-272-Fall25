#include <iostream>
using namespace std;

class MyNumber {
private:
    int value; // internal stored int
public:
    // constructor
    MyNumber(int val = 0) {
        value = val;
    }

    // getter to read the stored value
    int getvalue() const {
        return value;
    }

    // overload the unary minus: -num
    // this does not change the original object
    MyNumber operator-() const {
        return MyNumber(-value);
    }

    // overload the prefix ++: ++num
    // this will change the current object (increments value)
    MyNumber operator++() {
        ++value; // increases the stored value by 1
        return MyNumber(value);
    }
};

int main() {
    MyNumber num(10);
    cout << "Original value: " << num.getvalue() << endl;

    // using the overloaded unary minus operator
    MyNumber negative = -num;
    cout << "After applying -num: " << negative.getvalue() << endl;

    MyNumber incremented = ++num;
    cout << "After applying ++num, num is: " << num.getvalue() << endl;
    cout << "Value returned by ++num: " << incremented.getvalue() << endl;

    return 0;
}
