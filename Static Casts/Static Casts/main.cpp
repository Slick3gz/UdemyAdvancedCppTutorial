//
//  main.cpp
//  Static Casts
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

class Parent
{
public:
    void speak()
    {
        std::cout << "parent!" << std::endl;
    }
};

class Brother: public Parent
{
    
};

class Sister: public Parent
{
    
};

int main(int argc, const char * argv[]) {

    Parent parent;
    Brother brother;
    
    Parent *ppb = &brother;
    
    Brother *pbb = static_cast<Brother *>(ppb);
    
    std::cout << pbb << std::endl;
    
    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();
    
    return 0;
}
