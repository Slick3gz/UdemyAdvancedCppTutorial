#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

class Test
{
    int id;
    std::string name;
public:
    Test(int id, std::string name): id(id), name(name){}
    void print()
    {
        std::cout << id << ": " << name << std::endl;
    }
    bool operator<(Test &other) const
    {
        if(name == other.name)
        {
            return id < other.id;
        }
        else
        {
            return name < other.name;
        }
    }

/*
friend bool comp(const Test &a, const Test &b)
{
    if(a.name == b.name)
    {
        return a.id < b.id;
    }
    else
    {
        return a.name < b.name;
    }
}
*/
};

int main()
{
    std::cout << "<-------------------------------------------->" << std::endl;
    std::cout << "                   Vectors                    " << std::endl;
    std::vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(77, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    std::sort(tests.begin(), tests.end());

    for(int i = 0; i < tests.size(); i++)
    {
        tests[i].print();
    }

    std::cout << "<-------------------------------------------->" << std::endl;
    std::cout << "                   Deque                      " << std::endl;

    std::deque<Test> tests2;

    tests2.push_back(Test(5, "Mike"));
    tests2.push_back(Test(77, "Mike"));
    tests2.push_back(Test(10, "Sue"));
    tests2.push_back(Test(7, "Raj"));
    tests2.push_back(Test(3, "Vicky"));

    for(int i = 0; i < tests.size(); i++)
    {
        tests2[i].print();
    }

    std::cout << "<-------------------------------------------->" << std::endl;

    tests2.pop_back();

    std::cout << "Popped from back: " << std::endl;
    tests2.pop_back();
    std::cout << "Popped from back again: " << std::endl;

    for(int i = 0; i < tests.size(); i++)
    {
        tests2[i].print();
    }

    std::cout << "<-------------------------------------------->" << std::endl;
    tests2.pop_front();
    std::cout << "Popped from front: " << std::endl;

    for(int i = 0; i < tests.size(); i++)
    {
        tests2[i].print();
    }

    std::cout << "<-------------------------------------------->" << std::endl;
    for(std::deque<Test>::iterator it=tests2.begin(); it != tests2.end(); it++)
    {
        it->print();
    }
    return 0;
}
