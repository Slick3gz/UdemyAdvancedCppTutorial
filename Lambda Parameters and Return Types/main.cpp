#include <iostream>

void testGreet(void (*greet)(std::string))
{

    greet("Bob");
}

void runDivide(double (*divide)(double a, double b))
{
    auto rval = divide(9, 3);
    std::cout << rval << std::endl;
}
int main()
{

    auto pGreet= [](std::string name){ std::cout <<"Hello " << name << std::endl;};

    pGreet("Mike");

    testGreet(pGreet);

    auto pDivide = [](double a, double b) -> double
    {
        if(b == 0.0)
        {
            return 0;
        }
        return a/b;
    };

    std::cout << pDivide(10.0, 0) << std::endl;

    runDivide(pDivide);
    return 0;
}
