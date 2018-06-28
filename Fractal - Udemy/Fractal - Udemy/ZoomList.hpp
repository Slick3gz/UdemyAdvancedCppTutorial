//
//  ZoomList.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/27/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef ZoomList_hpp
#define ZoomList_hpp

#include <vector>
#include <utility>
#include "Zoom.hpp"

namespace slick {
    class ZoomList
    {
    private:
        int m_width{0};
        int m_height{0};
        std::vector<Zoom> zooms;
    public:
        ZoomList(int width, int height);
        void add(const Zoom& zoom);
        std::pair<double,double> doZoom(int x, int y);
    };
}

#endif /* ZoomList_hpp */
