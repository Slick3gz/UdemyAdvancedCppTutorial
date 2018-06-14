//
//  main.cpp
//  Structs and Padding
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>

/*
 
 Structs have padding for efficient memory hanlding.
 Have to remove the struct padding with #pragma directives
 
*/
#pragma pack(push, 1)

struct Person
{
    char c;
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main(int argc, const char * argv[]) {

    std::cout << sizeof(Person) << std::endl;
    return 0;
}
