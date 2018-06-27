//
//  main.cpp
//  Unique Pointers
//
//  Created by Slick on 6/25/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <memory>

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

class Temp
{
private:
    std::unique_ptr<Test[]> pTest;
    
public:
    Temp(): pTest(new Test[2])
    {
        
    }
};

int main(int argc, const char * argv[]) {
    
    Temp temp;
    
//    std::unique_ptr<Test[]> pTest(new Test[2]);
//
//    pTest[1].greet();
    
    std::cout << "Finished" << std::endl;
    
    return 0;
}
