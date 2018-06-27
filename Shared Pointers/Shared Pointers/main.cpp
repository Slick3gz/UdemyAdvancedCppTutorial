//
//  main.cpp
//  Shared Pointers
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

class Test
{
public:
    Test()
    {
        std::cout << "created" << std::endl;
    }
    
    void greet()
    {
        std::cout << "Hello" << std::endl;
    }
    
    ~Test()
    {
        std::cout << "destroyed" << std::endl;
    }
};


int main(int argc, const char * argv[]) {

    std::shared_ptr<Test> pTest2(nullptr);
    {
        std::shared_ptr<Test> pTest1 = std::make_shared<Test>();
    
        pTest2 = pTest1;
    
        
    }
    auto pTest3 = pTest2;
    std::cout << "Finished" << std::endl;
    return 0;
}
