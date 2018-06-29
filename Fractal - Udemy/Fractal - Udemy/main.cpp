//
//  main.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include "FractalCreator.hpp"

#include "RGB.hpp"
#include "Zoom.hpp"


int main(int argc, const char * argv[]) {
    
    slick::FractalCreator fractalCreator(800, 600);
    
    fractalCreator.addRange(0.0, slick::RGB(0,200,250));
    fractalCreator.addRange(0.02, slick::RGB(255,200,25));
    fractalCreator.addRange(0.479, slick::RGB(50,100,100));
    fractalCreator.addRange(0.688, slick::RGB(150,25,200));
    fractalCreator.addRange(1.0, slick::RGB(255,90,255));
    
    
    fractalCreator.addZoom(slick::Zoom(295, 202, 0.1));
    fractalCreator.addZoom(slick::Zoom(312, 304, 0.1));
    fractalCreator.run("test.bmp");
    std::cout << "Finished" << std::endl;
    return 0;
}
