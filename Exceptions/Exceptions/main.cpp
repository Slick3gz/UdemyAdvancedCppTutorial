//
//  main.cpp
//  Exceptions
//
//  Created by Slick on 6/10/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

enum class MyError
{
    BAD_ERROR  =            0,
    REALLY_BAD_ERROR =      1,
    EXTREMELY_BAD_ERROR =   2,
    EPIC_ERROR =            -999999,
};
void mightGoWrong()
{
    bool error1 = false;
    bool error2 = false;
    bool error3 = false;
    bool error4 = true;
    
    if(error1)
    {
        throw MyError::BAD_ERROR;
    }
    if(error2)
    {
        throw MyError::REALLY_BAD_ERROR;
    }
    if(error3)
    {
        throw MyError::EXTREMELY_BAD_ERROR;
    }
    if(error4)
    {
        throw MyError::EPIC_ERROR;
    }
}
void usesMightGoWrong()
{
    mightGoWrong();
}
int main(int argc, const char * argv[]) {
    try
    {
        mightGoWrong();
    }
    catch(MyError e)
    {
        switch (e) {
            case MyError::BAD_ERROR:
                std::cout << "A bad error occurred." << std::endl;
                break;
            case MyError::REALLY_BAD_ERROR:
                std::cout << "A really bad error occurred." << std::endl;
                break;
            case MyError::EXTREMELY_BAD_ERROR:
                std::cout << "An extremely bad error occurred." << std::endl;
                break;
            case MyError::EPIC_ERROR:
                std::cout << "An epic error occurred.  Write that shit down."  << std::endl;
                break;
        }
    }
    
    std::cout << "Still running" << std::endl;
    return 0;
}
