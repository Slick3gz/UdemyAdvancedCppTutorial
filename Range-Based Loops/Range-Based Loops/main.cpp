//
//  main.cpp
//  Range-Based Loops
//
//  Created by Slick on 6/16/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char * argv[]) {
    
    
    auto texts = {"one", "two", "three"};
    
    for(auto text: texts)
    {
        std::cout << text << std::endl;
    }
    
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(11);
    numbers.push_back(13);
    
    for(auto number: numbers)
    {
        std::cout << number << std::endl;
    }
    
    std::string hello = "Hello";
    for (auto c: hello)
    {
        std::cout << c << std::endl;
    }
    return 0;
}
