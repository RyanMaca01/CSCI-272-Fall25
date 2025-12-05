#include <iostream>
#include "Integer.h"

int main() {
    Integer num1(5);
    Integer num2(7);

    Integer sum = num1 + num2;

    std::cout << "Sum: " << sum.getValue() << std::endl;

    return 0;
}
