//
//  main.cpp
//  Custom Objects as Map Keys
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <map>

class Person
{
private:
    std::string name;
    int age;
    
public:
    Person(): name(""), age()
    {}
    
    Person(const Person &other)
    {
        name = other.name;
        age = other.age;
    }
    Person(std::string name, int age) : name(name), age(age)
    {
        
    }
    void print() const
    {
        std::cout << name << ": " << age << std::flush;
    }
    
    bool operator<(const Person &other) const
    {
        if(name == other.name)
        {
            return age < other.age;
        }
        else
        {
            return name < other.name;
        }
        
    }
};


int main(int argc, const char * argv[]) {
    
    std::map<Person, int> people;
    
    people[Person("Mike", 40)] = 40;
    people[Person("Vicky", 30)] = 30;
    people[Person("Raj", 20)] = 20;
    people[Person("Mike", 23452)] = 1234;
    
    for(std::map<Person, int>::iterator it =  people.begin(); it != people.end(); it++)
    {
        std::cout << it->second << ": " << std::flush;
        it->first.print();
        std::cout << std::endl;
    }
    
    
    
    return 0;
}

