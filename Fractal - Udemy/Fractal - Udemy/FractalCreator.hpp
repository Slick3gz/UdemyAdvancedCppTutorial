//
//  FractalCreator.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/28/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef FractalCreator_hpp
#define FractalCreator_hpp

#include <string>
#include "Zoom.hpp"

namespace slick
{
    class FractalCreator
    {
    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        
        void calculateIteration();
        void drawFractal();
        void writeBitmap(std::string name);
        void addZoom(const Zoom& zoom);
    };
}
#endif /* FractalCreator_hpp */
