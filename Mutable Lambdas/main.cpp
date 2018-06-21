#include <iostream>


int main()
{
    int cats = 5;

    [cats]() mutable
    {
        cats = 10;
        std::cout << cats << std::endl;
    }();

    std::cout << cats << std::endl;

    return 0;
}
