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
#include <math.h>
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "ZoomList.hpp"
#include "FractalCreator.hpp"

int main(int argc, const char * argv[]) {
    
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    slick::Bitmap bitmap(WIDTH,HEIGHT);
    
    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
    
    
    double min = 999999;
    double max = -999999;
    
    slick::ZoomList zoomList(WIDTH, HEIGHT);
    
    zoomList.add(slick::Zoom(WIDTH/2, HEIGHT/2, 4.0/HEIGHT));
    zoomList.add(slick::Zoom(350, HEIGHT - 202, 0.1));
    zoomList.add(slick::Zoom(322, HEIGHT - 304, 0.1));
    zoomList.add(slick::Zoom(322, HEIGHT - 304, 0.01));
    
    // Pointer to hold the iteration counts
    std::unique_ptr<int[]> histogram(new int[slick::Mandelbrot::MAX_ITERATIONS]{});
    std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});
    
    for(int y{0}; y < HEIGHT; ++y)
    {
        for(int x{0}; x < WIDTH; ++x)
        {
            
            std::pair<double, double> coords = zoomList.doZoom(x, y);
            
            int iterations = slick::Mandelbrot::getIterations(coords.first, coords.second);
            
            fractal[y*WIDTH+x] = iterations;
            
            if(iterations != slick::Mandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
            
            
        }
    }
    
    int total{0};
    for(auto i{0}; i < slick::Mandelbrot::MAX_ITERATIONS; ++i)
    {
        total += histogram[i];
    }
    
    for(int y{0}; y < HEIGHT; ++y)
    {
        for(int x{0}; x < WIDTH; ++x)
        {
            std::uint8_t red{0};
            std::uint8_t green{0};
            std::uint8_t blue{0};
            
            int iterations = fractal[y*WIDTH+x];
            
            if(iterations!= slick::Mandelbrot::MAX_ITERATIONS)
            {
                double hue{0.0};
                
                for(auto i{0}; i <= iterations; ++i)
                {
                    hue += (double)histogram[i]/total;
                }
                
                green = pow(255, hue);
            }
            
            bitmap.setPixel(x,y, red, green, blue);
            
        }
    }
    bitmap.write("test.bmp");
    return 0;
}
