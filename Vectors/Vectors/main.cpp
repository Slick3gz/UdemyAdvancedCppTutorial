//
//  main.cpp
//  Vectors
//
//  Created by Slick on 6/11/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include <iostream>
#include <vector>

class Person
{
private:
    std::string m_name;
    int m_age;
    float m_height;
    
public:
    Person(std::string name, int age, float height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    }
    Person()
    {
        m_name = "John Doe";
        m_age = 0;
        m_height = 0.0;
    }
    const void printPerson()
    {
        std::cout << m_name << m_age << m_height << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<std::string> strings;
    
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    
    for(int i = 0; i < strings.size(); ++i)
    {
        std::cout << strings[i] << std::endl;
    }
    
    std::cout << "-------------------------------------" << std::endl;
    for(std::vector<std::string>::iterator itr = strings.begin();
        itr != strings.end();
        ++itr)
    {
        std::cout << *itr << std::endl;
    }
    
    /*
     
     Needs more work.  Operator overloading, etc.
     ------------> Does not work <---------------
     
    std::vector<Person> people;
    
    people[0] = {"Marivin", 44, 65.3};
    people[1] = {"Alex", 13, 43.2};
    
    for(std::vector<Person>::iterator PersonIterator = people.begin();
        PersonIterator != people.end();
        PersonIterator++)
    {
        PersonIterator->printPerson();
    }
    ------------> Does not work <------------------
     */
    
    return 0;
}
