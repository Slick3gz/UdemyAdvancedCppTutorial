//
//  main.cpp
//  Overloading Equality Test
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"


int main(int argc, const char * argv[]) {
    
    Slick::Complex c1(3,2);
    Slick::Complex c2(3,1);
    if(c1 == c2)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal" << std::endl;
    }
    
    if(c1 != c2)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }
    return 0;
}
