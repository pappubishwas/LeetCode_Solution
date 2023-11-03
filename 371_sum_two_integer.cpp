#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int addNumbers(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = (unsigned int)carry << 1;
    }
    return a;
}

int main() {
    int number1 = -5; // Example first number
    int number2 = 3; // Example second number

    int sum = addNumbers(number1, number2);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
