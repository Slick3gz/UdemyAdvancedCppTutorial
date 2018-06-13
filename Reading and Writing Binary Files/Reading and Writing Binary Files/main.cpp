//
//  main.cpp
//  Reading and Writing Binary Files
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <fstream>
/*
 
 Structs have padding for efficient memory hanlding.
 Have to remove the struct padding with #pragma directives
 
 */
#pragma pack(push, 1)

struct Person
{
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main() {
    
    Person someone = {"Frodo" , 220, 0.8};
    
    std::string fileName = "test.bin";
    
    // Write binary file
    std::ofstream outputFile;
    
    outputFile.open(fileName, std::ios::binary);
    
    if(outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();
    }
    else
    {
        std::cout << "Could not create file " + fileName;
    }
    
    // Read binary file
    Person someoneElse = {};
    
    std::ifstream inputFile;
    
    inputFile.open(fileName, std::ios::binary);
    
    if(inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else
    {
        std::cout << "Could not read file " + fileName;
    }
    
    std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;
    return 0;
}
