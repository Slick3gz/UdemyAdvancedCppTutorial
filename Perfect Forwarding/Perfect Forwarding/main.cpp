//
//  main.cpp
//  Perfect Forwarding
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

class Test
{

};

template<typename T>
void call(T &&arg)
{
    check(std::forward<T>(arg));
}

void check(Test &test)
{
    std::cout << "Lvalue" << std::endl;
}

void check(Test &&test)
{
    std::cout << "Rvalue" << std::endl;
}

int main(int argc, const char * argv[]) {

    Test test;
    call(test);
    

    return 0;
}
