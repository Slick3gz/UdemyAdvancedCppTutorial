//
//  main.cpp
//  Sets
//
//  Created by Slick on 6/12/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <set>

class Test
{
public:
    Test(): id(0), name(""){}
    Test(int id, std::string name): id(id), name(name){}
    void print() const
    {
        std::cout << id << ": " << name << std::endl;
    }
    bool operator<(const Test &other) const
    {
        return name < other.name;
    }
    
private:
    int id;
    std::string name;

};
int main(int argc, const char * argv[]) {

    std::set<int> numbers;
    
    numbers.insert(30);
    numbers.insert(40);
    numbers.insert(50);
    numbers.insert(60);
    numbers.insert(70);
    
    for(std::set<int>::iterator it= numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    std::set<int>::iterator itFind = numbers.find(30);
    
    if(itFind != numbers.end())
        std::cout << "Found: " << *itFind << std::endl;
    
    if(numbers.count(30))
        std::cout << "Number found." << std::endl;
    
    std::set<Test> tests;
    
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(20, "Joe"));
    tests.insert(Test(222, "Joe"));
    tests.insert(Test(30, "Sue"));
    
    
    for(std::set<Test>::iterator it= tests.begin(); it != tests.end(); it++)
    {
        it->print();
    }
    
    return 0;
}

