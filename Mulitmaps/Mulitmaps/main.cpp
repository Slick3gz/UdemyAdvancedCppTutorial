//
//  main.cpp
//  Mulitmaps
//
//  Created by Slick on 6/12/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <map>

int main(int argc, const char * argv[]) {
    
    std::multimap<int, std::string> lookup;
    
    lookup.insert(std::make_pair(30, "Mike"));
    lookup.insert(std::make_pair(10, "Vicky"));
    lookup.insert(std::make_pair(30, "Raj"));
    lookup.insert(std::make_pair(20, "Bob"));
    
    // Start iterator from the beginning
    for(std::multimap<int, std::string>::iterator it=lookup.begin(); it != lookup.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    
    std::cout << "<---------------------------------------->" << std::endl;
    
    // Start iterator from first element "found" matching
    for(std::multimap<int, std::string>::iterator it=lookup.find(30); it != lookup.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    
    std::cout << "<---------------------------------------->" << std::endl;
    
    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its = lookup.equal_range(30);
    
    for(std::multimap<int, std::string>::iterator it=its.first; it != its.second; it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << "<---------------------------------------->" << std::endl;
    
    // Save some typing with auto!!
    // This for loop is the same as above but C++ automatically
    // determines the type
    auto its2 = lookup.equal_range(30);
    
    for(std::multimap<int, std::string>::iterator it=its2.first; it != its2.second; it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    
    return 0;
}
