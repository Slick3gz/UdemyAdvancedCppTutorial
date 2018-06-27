//
//  Mandelbrot.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/27/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//
#include <complex>
#include "Mandelbrot.hpp"

namespace slick
{
    Mandelbrot::Mandelbrot(){}
    Mandelbrot::~Mandelbrot(){}
    int Mandelbrot::getIterations(double x, double y)
    {

        std::complex<double> z = 0;
        std::complex<double> c(x, y);
        
        int iterations = 0;
        
        while(iterations < MAX_ITERATIONS)
        {
            z = z*z + c;
            
            if(std::abs(z) > 2)
            {
                break;
            }
            ++iterations;
        }
        return iterations;
    }
}
