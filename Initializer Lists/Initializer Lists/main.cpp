//
//  main.cpp
//  Initializer Lists
//
//  Created by Slick on 6/17/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>
#include <initializer_list>

class Test
{
public:
    Test(std::initializer_list<std::string> texts)
    {
        for(auto value: texts)
        {
            std::cout << value << std::endl;
        }
    }
    void print(std::initializer_list<std::string> texts)
    {
        for(auto value: texts)
        {
            std::cout << value << std::endl;
        }
    }
};



int main() {
   
    std::vector<int> numbers {1, 3, 4, 6};
    std::cout << numbers[2] << std::endl;
    
    Test test{"apple", "orange", "bananan"};
    test.print({"one", "two", "three", "four"});
    return 0;
}
