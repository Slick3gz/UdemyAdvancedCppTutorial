//
//  main.cpp
//  The Auto Keyword
//
//  Created by Slick on 6/14/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

template <class T, class S>
auto test(T value, S value2) -> decltype(value+value2)
{
    return value + value2;
}

int get()
{
    return 999;
}
auto test2() -> decltype(get())
{
    return get();
}

int main(int argc, const char * argv[]) {
    
    auto value = 7;
    auto text = "Hello";
    std::cout << test(6, 5) << std::endl;
    std::cout << test2() << std::endl;
    return 0;
}
