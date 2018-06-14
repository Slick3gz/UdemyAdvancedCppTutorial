//
//  main.cpp
//  Vectors and Memory
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    std::vector<double> numbers(0);
    
    std::cout << "Size: " << numbers.size() << std::endl;
    
    int capacity = numbers.capacity();
    std::cout << "Capacity: " << capacity << std::endl;
    
    for(int i = 0; i < 10000; i++)
    {
            if(numbers.capacity() != capacity)
            {
                capacity = numbers.capacity();
                std::cout  << "Capactiy: " << capacity << std::endl;
    
            }
        numbers.push_back(i);
    }
    
    return 0;
}
