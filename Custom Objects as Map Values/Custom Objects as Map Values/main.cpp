//
//  main.cpp
//  Custom Objects as Map Values
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
        std::cout << "Copy constructor running!" << std::endl;
        std::cout << "Other name: " << other.name << " Other age: " << other.age << std::endl;
        name = other.name;
        age = other.age;
    }
    Person(std::string name, int age) : name(name), age(age)
    {
        
    }
    void print() const
    {
        std::cout << name << ": " << age << std::endl;
    }
};


int main(int argc, const char * argv[]) {

    std::map<int, Person> people;
    
    people[0] = Person("Mike", 40);
    people[1] = Person("Vicky", 30);
    people[2] = Person("Raj", 20);
    
    people.insert(std::make_pair(55, Person("Bob", 45)));
    people.insert(std::make_pair(99, Person("Sue", 25)));
    
    for(std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++)
    {
        it->second.print();
    }
    
    
    
    return 0;
}
