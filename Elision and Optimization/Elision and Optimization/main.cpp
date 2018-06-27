//
//  main.cpp
//  Elision and Optimization
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

class Test
{
public:
    Test()
    {
        std::cout << "constructor" << std::endl;
    }
    
    Test(int i)
    {
        std::cout << "parameterized constructor" << std::endl;
    }
    
    Test(const Test &other)
    {
        std::cout << "copy constructor" << std::endl;
    }
    
    Test &operator=(const Test &other)
    {
        std::cout << "assignment" << std::endl;
        return *this;
    }
    
    ~Test()
    {
        std::cout << "destructor" << std::endl;
    }
    
    friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test &test)
{
    out << "Hello from test";
    return out;
}

Test getTest()
{
    return Test();
}

int main(int argc, const char * argv[]) {

    Test test1 = getTest();
    
    std::cout << test1 << std::endl;

    return 0;
}
