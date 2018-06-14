//
//  main.cpp
//  Reading Text Files
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {

    std::string inFileName = "test.txt";
    
    std::ifstream inFile;
    
    inFile.open(inFileName);
    
    if(inFile.is_open())
    {
        std::string line;
        
        while(!inFile.eof())
        {
            getline(inFile, line);
            std::cout << line << std::endl;
        }
        
        inFile.close();
    }
    else
    {
        std::cout << "Cannot open file: " << inFileName << std::endl;
    }
    
    return 0;
}
