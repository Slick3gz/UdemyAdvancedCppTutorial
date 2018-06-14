//
//  main.cpp
//  A Complex Number Class
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {

    Slick::Complex c1(2,3);
    Slick::Complex c2(c1);
    
    Slick::Complex c3;
    c3 = c2 = c1;
    
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;
    return 0;
}
