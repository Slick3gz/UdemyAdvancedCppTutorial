//
//  Bitmap.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <string>
#include <cstdint>

namespace slick
{
    class Bitmap
    {
    private:
        int m_width{0};
        int m_height{0};
        
    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
        bool write(std::string filename);
        virtual ~Bitmap();
    };
}

#endif /* Bitmap_hpp */
