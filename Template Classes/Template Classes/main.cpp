//
//  main.cpp
//  Template Classes
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

template <class T, class K>
class Test {
    T obj;
    K value;
    
public:
    Test(T obj, K value)
    {
        this->obj= obj;
        this->value = value;
    }
    
    void print()
    {
        std::cout << obj << ": " << value << std::endl;
    }
};
int main(int argc, const char * argv[]) {
    
    Test<std::string, int > test1("Mike", 10);
    test1.print();
    
    return 0;
}
