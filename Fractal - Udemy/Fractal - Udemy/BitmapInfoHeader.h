//
//  BitmapInfoHeader.h
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef BitmapInfoHeader_h
#define BitmapInfoHeader_h

#include <cstdint>

#pragma pack(2)

namespace slick
{
    
    struct BitmapInfoHeader
    {
        std::int32_t headerSize{40};
        std::int32_t width;
        std::int32_t height;
        std::int16_t planes{1};
        std::int16_t bitsPerPixel{24};
        std::int32_t compression{0};
        std::int32_t dataSize{0};
        std::int32_t horizontalResolution{2400};
        std::int32_t veritcalResolution{2400};
        std::int32_t colors{0};
        std::int32_t importantColors{0};
    };

}
#endif /* BitmapInfoHeader_h */
