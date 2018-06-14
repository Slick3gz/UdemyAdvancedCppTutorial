//
//  main.cpp
//  Lists
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <list>

int main(int argc, const char * argv[]) {

    std::list<int> numbers;
    
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    
    numbers.push_front(0);
    std::list<int>::iterator it=numbers.begin();

    it++;
    numbers.insert(it, 100);
    std::cout << "Element: " << *it << std::endl;
    
    std::list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    
    std::cout << "Element: " << *eraseIt << std::endl;
    
    std::list<int>::iterator itr=numbers.begin();
    while(itr != numbers.end())
    {
        if(*itr == 2)
        {
            numbers.insert(itr, 1234);
            std::cout << "inserted..." << std::endl;
        }
        else
        {
            std::cout << "Incrementing from '*itr == 2' else statement" << std::endl;
            itr++;
        }
        
        if(*itr == 1)
        {
            itr = numbers.erase(itr);
            std::cout << "Erased..." <<std::endl;
        }
        else
        {
            std::cout << "Incrementing from else of '*itr == 1' statement" << std::endl;
            itr++;
        }
        itr++;
        
    }
    
    for(std::list<int>::iterator it=numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    return 0;
}
