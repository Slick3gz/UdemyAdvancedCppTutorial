//
//  BitmapFileHeader.h
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h

#include <cstdint>

#pragma pack(2)

struct BitmapFileHeader
{
    char header[2]{'B', 'M'};
    std::int32_t fileSize;
    std::int32_t reserved{0};
    std::int32_t dataOffset;
};

#endif /* BitmapFileHeader_h */
