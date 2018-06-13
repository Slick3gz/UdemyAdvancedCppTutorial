//
//  main.cpp
//  Maps
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <map>

int main(int argc, const char * argv[]) {
    
    std::map<std::string, int> ages;
    
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages ["Vicky"] = 30;
    
    ages["Mike"] = 70;
    
    
    ages.insert(std::make_pair("Peter", 100));
    
    std::cout << ages["Raj"] << std::endl;
    
    if(ages.find("Vicky") != ages.end())
    {
        std::cout << "Found Vicky" << std::endl;
    }
    else
    {
        std::cout << "Key not found" << std::endl;
    }
    
    for(std::map<std::string, int>::iterator it=ages.begin(); it != ages.end(); it++)
    {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    
    for(std::map<std::string, int>::iterator it=ages.begin(); it != ages.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
