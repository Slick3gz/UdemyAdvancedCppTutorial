//
//  main.cpp
//  Rvalue References
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>

class Test
{
private:
    static const int SIZE=100;
    int *_pBuffer;
public:
    Test()
    {
        std::cout << "constructor" << std::endl;
        _pBuffer = new int[SIZE]{};
        // initializing array bytes
        // 3 options
        //-------> _pBuffer = new int[SIZE]{};
        //-------> _pBuffer = new int[SIZE]();
        //-------> memset(_pBuffer, 0, sizeof(int)*SIZE);
    }
    
    Test(int i)
    {
        std::cout << "parameterized constructor" << std::endl;
        _pBuffer = new int[SIZE]{};
        
        for(int i=0; i < SIZE; i++)
        {
            _pBuffer[i] = 7*i;
        }
    }
    
    Test(const Test &other)
    {
        std::cout << "copy constructor" << std::endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        
    }
    
    Test &operator=(const Test &other)
    {
        std::cout << "assignment" << std::endl;
        
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }
    
    ~Test()
    {
        std::cout << "destructor" << std::endl;
        delete [] _pBuffer;
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

void check(const Test &value)
{
    std::cout << "lValue function!" << std::endl;
}

void check(Test &&value)
{
    std::cout << "rValue function!" << std::endl;
}

int &checkInt(int &value)
{
    std::cout << "Lvalue int: " << value << std::endl;
    return value;
}

int &checkInt(int &&value)
{
    std::cout << "Rvalue int: " << value << std::endl;
    return value;
}

int main(int argc, const char * argv[]) {
    
    Test test1 = getTest();
    
    std::cout << test1 << std::endl;
    
    std::vector<Test> vec;
    vec.push_back(Test());
    
    Test &lTest1 = test1;
    
    Test &&rtest1 = getTest();
    
    check(test1);
    check(getTest());
    check(Test());
    
    int myInt = 3;
    int &rMyInt = myInt;
    
    checkInt(myInt);
    checkInt(rMyInt);
    checkInt(int(9));
    checkInt(34.2);
    
    int &&Rvalue = int(9);
    checkInt(Rvalue);
    return 0;
}
