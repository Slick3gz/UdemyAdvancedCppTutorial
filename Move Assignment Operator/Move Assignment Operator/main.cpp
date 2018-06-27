//
//  main.cpp
//  Move Assignment Operator
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
    int *_pBuffer{nullptr};
public:
    Test()
    {
        _pBuffer = new int[SIZE]{};
        // initializing array bytes
        // 3 options
        //-------> _pBuffer = new int[SIZE]{};
        //-------> _pBuffer = new int[SIZE]();
        //-------> memset(_pBuffer, 0, sizeof(int)*SIZE);
    }
    
    Test(int i)
    {
        _pBuffer = new int[SIZE]{};
        
        for(int i=0; i < SIZE; i++)
        {
            _pBuffer[i] = 7*i;
        }
    }
    
    Test(const Test &other)
    {
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        
    }
    
    Test(Test &&other)
    {
        std::cout << "Move constructor" << std::endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }
    
    Test &operator=(const Test &other)
    {
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }
    
    Test &operator=(Test &&other)
    {
        std::cout << "Move Assignment" << std::endl;
        delete [] _pBuffer;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
        
        return *this;
    }
    
    ~Test()
    {
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

int main(int argc, const char * argv[]) {
    
    
    
    std::vector<Test> vec;
    vec.push_back(Test());
    
    Test test;
    test = getTest();
    
    
    return 0;
}
