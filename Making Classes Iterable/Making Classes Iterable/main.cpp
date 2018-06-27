//
//  main.cpp
//  Making Classes Iterable
//
//  Created by Slick on 6/16/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <string>
#include "ring.hpp"

int main() {
    
    ring<std::string> textring(3);
    
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");
    textring.add("six");
    textring.add("seven");
    
    
    for(int i = 0; i < textring.size(); i++)
    {
        std::cout << textring.get(i) << std::endl;
    }
    
    /*
     Output should be
     four
     one
     two
     */
    
    for(ring<std::string>::iterator it=textring.begin(); it != textring.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    for(auto value : textring)
    {
        std::cout << value << std::endl;
    }
    return 0;
}
