//
//  FractalCreator.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/28/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <memory>
#include <math.h>
#include "FractalCreator.hpp"
#include "Bitmap.hpp"
#include "Mandelbrot.hpp"
#include "ZoomList.hpp"

void slick::FractalCreator::run(std::string name)
{
    
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(name);
}
void slick::FractalCreator::addZoom(const Zoom& zoom)
{
    m_zoomList.add(zoom);
}
void slick::FractalCreator::addRange(double rangeEnd, const slick::RGB& rgb)
{
    m_ranges.push_back(rangeEnd*slick::Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);
    
    if(m_bGotFirstRange)
    {
        m_rangeTotals.push_back(0);
    }
    m_bGotFirstRange = true;
    
    
}
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
            int iterations = m_fractal[y*m_width+x];
            
            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];
            
            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range+1];
            RGB colorDiff = endColor - startColor;
            
            std::uint8_t red{0};
            std::uint8_t green{0};
            std::uint8_t blue{0};
            
            
            
            if(iterations!= slick::Mandelbrot::MAX_ITERATIONS)
            {
               
                int totalPixels{0};
                
                for(auto i{rangeStart}; i <= iterations; ++i)
                {
                    totalPixels += m_histogram[i];
                }
                red = startColor.r + colorDiff.r*(double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g*(double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b*(double)totalPixels/rangeTotal;
                
            }
            
            m_bitmap.setPixel(x,y, red, green, blue);
            
        }
    }
}
void slick::FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;
    
    for(int i = 0; i < slick::Mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixels = m_histogram[i];
        
        if(i >= m_ranges[rangeIndex+1])
        {
            rangeIndex++;
        }
        m_rangeTotals[rangeIndex] += pixels;
    }
    
}
void slick::FractalCreator::writeBitmap(std::string name)
{
    m_bitmap.write(name);
}

int slick::FractalCreator::getRange(int iterations) const
{
    int range = 0;
    
    for(int i = 1; i < m_ranges.size(); i++)
    {
        range = i;
        
        if(m_ranges[i] > iterations)
        {
            break;
        }
    }
    
    range--;
    
    assert(range > -1);
    assert(range < m_ranges.size());
    
    return range;
}
