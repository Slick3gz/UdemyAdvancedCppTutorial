//
//  FractalCreator.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/28/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//
#include <math.h>
#include <memory>
#include <math.h>
#include "FractalCreator.hpp"
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "ZoomList.hpp"

slick::FractalCreator::FractalCreator(int width, int height): m_width(width),
    m_height(height),
    m_histogram(new int[slick::Mandelbrot::MAX_ITERATIONS]{0}),
    m_fractal(new int[m_width*m_height]{0}),
    m_bitmap(m_width, m_height),
    m_zoomList(m_width, m_height)
{
    m_zoomList.add(slick::Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}
slick::FractalCreator::~FractalCreator()
{
    
}

void slick::FractalCreator::calculateIteration()
{
    for(int y{0}; y < m_height; ++y)
    {
        for(int x{0}; x < m_width; ++x)
        {
            
            std::pair<double, double> coords = m_zoomList.doZoom(x, y);
            
            int iterations = slick::Mandelbrot::getIterations(coords.first, coords.second);
            
            m_fractal[y*m_width+x] = iterations;
            
            if(iterations != slick::Mandelbrot::MAX_ITERATIONS)
            {
                m_histogram[iterations]++;
            }
            
            
        }
    }
}

void slick::FractalCreator::calculateTotalIterations()
{

    for(auto i{0}; i < slick::Mandelbrot::MAX_ITERATIONS; ++i)
    {
        m_total += m_histogram[i];
    }
}
void slick::FractalCreator::drawFractal()
{
    for(int y{0}; y < m_height; ++y)
    {
        for(int x{0}; x < m_width; ++x)
        {
            std::uint8_t red{0};
            std::uint8_t green{0};
            std::uint8_t blue{0};
            
            int iterations = m_fractal[y*m_width+x];
            
            if(iterations!= slick::Mandelbrot::MAX_ITERATIONS)
            {
                double hue{0.0};
                
                for(auto i{0}; i <= iterations; ++i)
                {
                    hue += (double)m_histogram[i]/m_total;
                }
                
                green = hue * 255;
            }
            
            m_bitmap.setPixel(x,y, red, green, blue);
            
        }
    }
}
void slick::FractalCreator::writeBitmap(std::string name)
{
    m_bitmap.write(name);
}
void slick::FractalCreator::addZoom(const Zoom& zoom)
{
    m_zoomList.add(zoom);
}

