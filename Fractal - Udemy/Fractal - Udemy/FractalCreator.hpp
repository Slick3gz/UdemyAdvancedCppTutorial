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
#include "Bitmap.hpp"
#include "ZoomList.hpp"

namespace slick
{
    class FractalCreator
    {
    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        
        void calculateIteration();
        void calculateTotalIterations();
        void drawFractal();
        void writeBitmap(std::string name);
        void addZoom(const Zoom& zoom);
    private:
        int m_width;
        int m_height;
        int m_total{0};
        // Pointer to hold the iteration counts
        std::unique_ptr<int[]> m_histogram;
        std::unique_ptr<int[]> m_fractal;
        slick::Bitmap m_bitmap;
        slick::ZoomList m_zoomList;
    };
}
#endif /* FractalCreator_hpp */
