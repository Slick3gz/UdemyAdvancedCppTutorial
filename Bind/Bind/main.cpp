//
//  main.cpp
//  Bind
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <functional>

using namespace std::placeholders;

class Test
{
public:
    int add(int a, int b, int c)
    {
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a + b + c;
    }
};

int run(std::function<int(int, int)> func)
{
    return func(7,3);
    
}

int main(int argc, const char * argv[]) {

    Test test;
    
    auto calculator = std::bind(&Test::add, test, _2, 100,_1);
    
    std::cout << run(calculator) << std::endl;
    
    
    return 0;
}
