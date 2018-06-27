//
//  main.cpp
//  Constructs and Memory
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
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

int main(int argc, const char * argv[]) {
    
    Test test1 = getTest();
    
    std::cout << test1 << std::endl;
    
    return 0;
}
