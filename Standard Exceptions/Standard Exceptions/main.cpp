//
//  main.cpp
//  Standard Exceptions
//
//  Created by Slick on 6/10/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char * pMemory = new char[9999999999999999];
        delete [] pMemory;
    }
};

int main(int argc, const char * argv[]) {
    try
    {
        CanGoWrong wrong;
    }
    catch(std::bad_alloc &e)
    {
        std::cerr << "Caught Exception: " << e.what()  << std::endl;
    }
    
    return 0;
}
