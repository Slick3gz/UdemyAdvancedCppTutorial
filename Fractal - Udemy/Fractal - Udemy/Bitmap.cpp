//
//  Bitmap.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include "Bitmap.hpp"

namespace slick
{
    slick::Bitmap::Bitmap(int width, int height): m_width(width), m_height(height)
    {
        
    }
    
    bool slick::Bitmap::write(std::string filname)
    {
        return false;
    }
    
    void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
    {
        
    }
    slick::Bitmap::~Bitmap(){}
}
