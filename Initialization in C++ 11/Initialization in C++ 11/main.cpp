//
//  main.cpp
//  Initialization in C++ 11
//
//  Created by Slick on 6/17/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    
    int value{5};
    
    std::cout << value << std::endl;
    
    std::string text{"Hello"};
    std::cout << text << std::endl;
    
    int numbers[]{1, 2, 4};
    std::cout << numbers[1] << std::endl;
    
    
    int *pInts = new int[3]{1, 2, 3};
    std::cout << pInts[1] << std::endl;
    delete [] pInts;
    
    int value1{};
    std::cout << value1 << std::endl;
    int *pSomething{};
    std::cout << pSomething << std::endl;
    
    struct
    {
        int value;
        std::string text;
        
    }s1{5, "Hi"};
    
    std::cout << s1.text << std::endl;
    
    std::vector<std::string> lists{"one", "two", "three"};
    
    std::cout << lists[2] << std::endl;
    return 0;
}
