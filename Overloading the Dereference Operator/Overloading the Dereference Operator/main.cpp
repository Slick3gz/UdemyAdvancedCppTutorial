//
//  main.cpp
//  Overloading the Dereference Operator
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"

int main(int argc, const char * argv[]) {
    Slick::Complex c1(2,4);
    
    std::cout << *c1 + *Slick::Complex(4,3) << std::endl;
    return 0;
}
