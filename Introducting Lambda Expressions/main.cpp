#include <iostream>


void test(void (*pFunc)())
{
    pFunc();
}
int main()
{
    auto func = [](){ std::cout << "Hello" << std::endl;};

    func();

    test(func);
    test([](){ std::cout << "Hello again" << std::endl;});
    return 0;
}
