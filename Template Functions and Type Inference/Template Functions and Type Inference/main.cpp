//
//  main.cpp
//  Template Functions and Type Inference
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

template<class T>
void print(T n)
{
    std::cout << "Template version: " << n << std::endl;
}

void print(int value)
{
    std::cout << "Non-template version: " << value << std::endl;
}

template<class T>
void show()
{
    std::cout << T() << std::endl;
}

int main(int argc, const char * argv[]) {
    
    print<std::string>("Hello");
    print<int>(5);
    
    print("Hi there");
    
    print(5);
    print<>(6);
    
    show<double>();
    return 0;
}
