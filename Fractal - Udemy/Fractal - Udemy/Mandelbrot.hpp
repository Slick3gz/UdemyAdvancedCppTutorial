//
//  Mandelbrot.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/27/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

namespace slick {
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS = 1000;
    public:
        Mandelbrot();
        virtual ~Mandelbrot();
        
        static int getIterations(double x, double y);
    };
}

#endif /* Mandelbrot_hpp */
