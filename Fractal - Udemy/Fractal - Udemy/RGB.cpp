//
//  RGB.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/28/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include "RGB.hpp"


slick::RGB::RGB(double r, double g, double b): r(r), g(g), b(b)
{
    
}

slick::RGB operator-(const slick::RGB& first, const slick::RGB& second)
{
    return slick::RGB(first.r - second.r,
                      first.g - second.g,
                      first.b - second.b);
}
