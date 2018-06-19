//
//  main.cpp
//  Decltype Typeid and Name Mangling
//
//  Created by Slick on 6/14/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <typeinfo>

int main(int argc, const char * argv[]) {
    
    std::string value;
    std::cout << typeid(value).name() << std::endl;
    
    decltype(value) name = "Bob";
    
    std::cout << typeid(value).name() << std::endl;
    
    std::cout << name << std::endl;
    return 0;
}
