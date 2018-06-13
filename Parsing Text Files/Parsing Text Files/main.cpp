//
//  main.cpp
//  Parsing Text Files
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {

    std::string filename = "stats.txt";
    std::ifstream input;
    
    input.open(filename);
    
    if(!input.is_open())
    {
        return 1;
    }
    
    while(input)
    {
        std::string line;
        
        getline(input, line, ':');
        
        int population;
        input >> population;
        
        input.get();
        
        if(!input)
            break;
        std::cout << "'" << line << "'" <<  " -- '" << population << "'" <<  std::endl;
    }
    
    input.close();
    
    return 0;
}
