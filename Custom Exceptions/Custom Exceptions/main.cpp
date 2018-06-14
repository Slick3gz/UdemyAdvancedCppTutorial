//
//  main.cpp
//  Custom Exceptions
//
//  Created by Slick on 6/10/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <exception>

class MyException: public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Something bad happened";
    }
};

class Test
{
public:
    void goesWrong()
    {
        throw MyException();
    }
};


int main(int argc, const char * argv[]) {
    
    Test test;
    
    try
    {
        test.goesWrong();
    }
    catch(MyException &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
