//
//  ZoomList.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/27/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//
#include "ZoomList.hpp"

namespace slick {
    ZoomList::ZoomList(int width, int height): m_width(width), m_height(height)
    {
        
    }
    void ZoomList::add(const Zoom& zoom)
    {
        ZoomList::zooms.push_back(zoom);
        
        m_xCenter += (zoom.x - m_width/2)*m_scale;
        m_yCenter += -(zoom.y - m_height/2)*m_scale;
        
        m_scale *= zoom.scale;

    }
    std::pair<double,double> ZoomList::doZoom(int x, int y)
    {
        double xFractal = (x - m_width/2)*m_scale + m_xCenter;
        double yFractal = (y - m_height/2)*m_scale + m_yCenter;
        return std::pair<double,double>(xFractal,yFractal);
        
    }
}
