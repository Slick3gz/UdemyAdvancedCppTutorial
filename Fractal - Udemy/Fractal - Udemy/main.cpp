//
//  main.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "Bitmap.hpp"


int main(int argc, const char * argv[]) {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    slick::Bitmap bitmap(WIDTH,HEIGHT);
    
    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
    
    

    
    for(int y{0}; y < HEIGHT; ++y)
    {
        for(int x{0}; x < WIDTH; ++x)
        {
            bitmap.setPixel(x, y, 255, 0, 0);
        }
    }
    
    bitmap.write("test.bmp");
    return 0;
}
