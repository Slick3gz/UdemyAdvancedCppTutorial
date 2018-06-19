#include <iostream>



int main()
{
    int one = 1;
    int two = 2;
    int three = 3;

    // Capture one and two by value
    [one, two](){std::cout << one << std::endl; }();

    // Capture all local variables by value, but capture
    // three by reference
    [=, &three](){three=7; std::cout << one << std::endl; }();
    std::cout << three << std::endl;

     // Capture all local variables by value, but capture
    // three by reference
    [&](){three=7; two=8; std::cout << one << std::endl; }();
    std::cout << two << std::endl;
    return 0;
}
