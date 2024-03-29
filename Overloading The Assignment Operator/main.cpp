#include <iostream>

class Test
{
private:
    int id;
    std::string name;

public:
    Test(): id(0), name("")
    {

    }
    Test(int id, std::string name): id(id), name(name)
    {

    }
    void print()
    {
        std::cout << id << ": " << name << std::endl;
    }
    const Test &operator=(const Test &other)
    {
        std::cout << "Assignment running..." << std::endl;
        id = other.id;
        name = other.name;
        return *this;
    }
    Test(const Test &other)
    {
        std::cout << "Copy Constructor running..." << std::endl;
        id = other.id;
        name = other.name;
    }
};

int main()
{
    Test test1(10, "Mike");
    std::cout << "Print test1: " << std::flush;
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;
    std::cout << "Print test2: " << std::flush;
    test2.print();

    Test test3;
    test3.operator=(test2);
    std::cout << "Print test3: " << std::flush;
    test3.print();

    std::cout << std::endl;

    Test test4 = test1;
    test4.print();
    return 0;
}
