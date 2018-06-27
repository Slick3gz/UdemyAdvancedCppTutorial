//
//  main.cpp
//  Initialization in C++ 98
//
//  Created by Slick on 6/17/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    int value[] = {1, 4, 5};
    
    std::cout << value[0] << std::endl;
    
    class C
    {
    public:
        std::string text;
        int id;
    };
    
    C c1 = {"Hello", 7};
    
    std::cout << c1.text << std::endl;
    
    struct S
    {
        std::string text;
        int id;
    };
    
    S s1 = {"Hello", 7};
    std::cout << s1.text << std::endl;
    
    struct R
    {
        std::string text;
        int id;
    } r1 = {"Hello", 7}, r2 = {"Hi", 9};
    
    std::cout << r1.text << std::endl;
    std::cout << r2.text << std::endl;
 
    std::vector<std::string> strings;
    
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    
    
    return 0;
}
