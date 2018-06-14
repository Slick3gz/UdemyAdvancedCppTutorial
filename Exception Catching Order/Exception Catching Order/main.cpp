//
//  main.cpp
//  Exception Catching Order
//
//  Created by Slick on 6/10/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

void goesWrong()
{
    bool error1Detected = false;
    bool error2Detected = true;
    
    if(error1Detected)
        throw std::bad_alloc();
    
    if(error2Detected)
        throw std::exception();
}


int main(int argc, const char * argv[]) {
   
    try
    {
        goesWrong();
    }
    
    /*
        bad_alloc is a sub class of std::exception
        Must list subclasses before base class because
        of polymorphism.
     */
    //------> Sub-Class <------
    catch(std::bad_alloc &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Catching bad_alloc" << std::endl;
    }
    //------> Base Class <-----
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Catching std::exception" << std::endl;
    }
    return 0;
}
