//
//  main.cpp
//  Two Dimensional Vectors
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid(3, std::vector<int>(4, 7));
    
    for(int row=0; row<grid.size(); row++)
    {
        for(int col=0; col<grid[row].size(); col++)
        {
            std::cout << grid[row][col] << std::flush;
            
        }
        std::cout << std::endl;
    }
    return 0;
}
