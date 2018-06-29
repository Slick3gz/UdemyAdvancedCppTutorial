//
//  RGB.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/28/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef RGB_hpp
#define RGB_hpp

#include <stdio.h>
namespace slick {
    struct RGB
    {
        double r;
        double g;
        double b;
        
        RGB(double r, double g, double b);
    };
    
    
}

slick::RGB operator-(const slick::RGB& first, const slick::RGB& second);
#endif /* RGB_hpp */
