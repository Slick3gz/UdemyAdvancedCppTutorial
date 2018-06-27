//
//  main.cpp
//  Reinterpret Cast
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

class Parent
{
public:
    virtual void speak()
    {
        std::cout << "parent!" << std::endl;
    }
};

class Brother: public Parent
{
public:
    void think()
    {
        std::cout << "thinking..." << std::endl;
    };
};

class Sister: public Parent
{
    
};

int main(int argc, const char * argv[]) {
    
    Parent parent;
    Brother brother;
    Sister sister;
    
    Parent *ppb = &brother;
    
    Sister *pbb = reinterpret_cast<Sister *>(ppb);
    
    if(pbb == nullptr)
    {
        std::cout << "Invalid cast" << std::endl;
    }
    else
    {
        std::cout << pbb << std::endl;
    }
    
    return 0;
}
