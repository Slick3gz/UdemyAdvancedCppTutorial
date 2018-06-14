//
//  main.cpp
//  Template Functions
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <map>
template<class T>
void print(T n)
{
    std::cout << n << std::endl;
}
int main(int argc, const char * argv[]) {
    
    print<std::string>("Hello");
    print<int>(5);
    
    print("Hi there");
    print(3.34392093+3934.23423);
    
    return 0;
}
