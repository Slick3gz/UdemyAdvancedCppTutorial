//
//  main.cpp
//  Writing Text Files
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <fstream>


int main() {

    std::ofstream outFile;
    std::string outputFileName = "text.txt";
    
    outFile.open(outputFileName);
    
    if(outFile.is_open())
    {
        for (int i = 1; i <= 10; ++i)
        {
            outFile << i << ".  A new line of text." << std::endl;
        }
        
        outFile.close();
    }
    else
    {
        std::cout << "Could not create file: " << outputFileName << std::endl;
    }
    
    return 0;
    
}
