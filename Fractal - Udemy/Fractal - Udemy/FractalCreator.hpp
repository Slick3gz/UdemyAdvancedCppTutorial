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
#include <vector>
#include "Zoom.hpp"
#include "Bitmap.hpp"
#include "ZoomList.hpp"
#include "RGB.hpp"

namespace slick
{
    class FractalCreator
    {
    public:
        void run(std::string);
        void addZoom(const Zoom& zoom);
        void addRange(double rangeEnd, const RGB& rgb);
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        int getRange(int iterations) const;
    private:
        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(std::string name);
        //int getRange(int iterations) const;
        
    private:
        int m_width;
        int m_height;
        int m_total{0};
        
        std::vector<int> m_ranges;
        std::vector<RGB> m_colors;
        std::vector<int> m_rangeTotals;
        
        bool m_bGotFirstRange{false};
        // Pointer to hold the iteration counts
        std::unique_ptr<int[]> m_histogram;
        std::unique_ptr<int[]> m_fractal;
        slick::Bitmap m_bitmap;
        slick::ZoomList m_zoomList;
    };
}
#endif /* FractalCreator_hpp */
