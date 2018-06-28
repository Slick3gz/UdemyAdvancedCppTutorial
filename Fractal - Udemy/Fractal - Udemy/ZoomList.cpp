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
    }
    std::pair<double,double> ZoomList::doZoom(int x, int y)
    {
        return std::pair<double,double>(0,0);
        
    }
}
