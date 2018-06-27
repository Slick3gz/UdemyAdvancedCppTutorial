//
//  Bitmap.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <fstream>
#include "Bitmap.hpp"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace slick
{
    slick::Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{})
    {
        
    }
    
    bool slick::Bitmap::write(std::string filename)
    {
        slick::BitmapFileHeader fileHeader;
        slick::BitmapInfoHeader infoHeader;
        
        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
        
        infoHeader.width = m_width;
        infoHeader.height = m_height;
        
        std::ofstream file;
        
        file.open(filename, std::ios::out|std::ios::binary);
        
        if(!file)
        {
            return false;
        }
        
        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)m_pPixels.get(), m_width*m_height*3);
        
        file.close();
        
        if(!file)
        {
            return false;
        }
        
        return false;
    }
    
    void slick::Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
    {
        std::uint8_t *pPixel = m_pPixels.get();
        
        pPixel += (y*3)*m_width+(x*3);
        
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }
    slick::Bitmap::~Bitmap(){}
}
