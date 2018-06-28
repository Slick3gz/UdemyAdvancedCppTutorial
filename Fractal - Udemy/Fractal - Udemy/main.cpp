//
//  main.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <memory>
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"


int main(int argc, const char * argv[]) {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    slick::Bitmap bitmap(WIDTH,HEIGHT);
    
    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
    
    
    double min = 999999;
    double max = -999999;
    
    // Pointer to hold the iteration counts
    std::unique_ptr<int[]> histogram(new int[slick::Mandelbrot::MAX_ITERATIONS + 1]{});
    
    for(int y{0}; y < HEIGHT; ++y)
    {
        for(int x{0}; x < WIDTH; ++x)
        {
            
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            int iterations = slick::Mandelbrot::getIterations(xFractal, yFractal);
            
            histogram[iterations]++;
            for(auto i{0}; i < sizeof(histogram); ++i)
            {
                std::cout << "Iterations for iterations[" << i << "]: " << histogram[i] << std::endl;
            }
                
            
            std::uint8_t color = (std::uint8_t)(256 * (double)iterations/slick::Mandelbrot::MAX_ITERATIONS);
            
            color = color*color*color;
            
            bitmap.setPixel(x,y, 0, color, 0);
            if(color < min) min = color;
            if(color > max) max = color;
        }
    }
    
    
    std::cout << min <<", "  << max << std::endl;
    bitmap.write("test.bmp");
    return 0;
}
