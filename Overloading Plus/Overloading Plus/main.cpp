//
//  main.cpp
//  Overloading Plus
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {
    Slick::Complex c1(3,4);
    Slick::Complex c2(2,3);
    Slick::Complex c3 = c1+c2;
    
    std::cout << c1 << std::endl;
    std::cout << c1+c2+c3 << std::endl;
    
    Slick::Complex c4(4,2);
    Slick::Complex c5 = c4 + 7;
    std::cout << c5 << std::endl;
    std::cout << 2.3 + c5 << std::endl;
    
    return 0;
}
