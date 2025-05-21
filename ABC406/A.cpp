#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    if (C > A || (C == A && D >= B)) std::cout << "No";
    else std::cout << "Yes";
}