//
//  Zoom.hpp
//  Fractal - Udemy
//
//  Created by Slick on 6/27/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef Zoom_hpp
#define Zoom_hpp

namespace slick {
    struct Zoom
    {
        int x{0};
        int y{0};
        double scale{0.0};
        
        Zoom(int x, int y, double scale): x(x), y(y), scale(scale)
        {
    
        }

    };
}

#endif /* Zoom_h */
