//
//  main.cpp
//  Fractal - Udemy
//
//  Created by Slick on 6/26/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>


#include "FractalCreator.hpp"

int main(int argc, const char * argv[]) {
    int height = 600;
    slick::FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(slick::Zoom(295, height - 202, 0.1));
    fractalCreator.addZoom(slick::Zoom(312, height - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");
    std::cout << "Finished" << std::endl;
    return 0;
}
