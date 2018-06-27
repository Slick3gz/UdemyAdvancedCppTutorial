//
//  main.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "Bitmap.hpp"


int main(int argc, const char * argv[]) {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    slick::Bitmap bitmap(WIDTH,HEIGHT);
    
    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
    
    
    double min = 999999;
    double max = -999999;
    
    for(int y{0}; y < HEIGHT; ++y)
    {
        for(int x{0}; x < WIDTH; ++x)
        {
            double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
//            double xFractal = sin(x);
//            double yFractal = sin(y);
            
            if(xFractal < min) min = yFractal;
            if(xFractal > max) max = yFractal;
        }
    }
    
    
    std::cout << min <<", "  << max << std::endl;
    bitmap.write("test.bmp");
    return 0;
}
