#include <iostream>
#include <ostream>

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
        id = other.id;
        name = other.name;
        return *this;
    }

    Test(const Test &other)
    {
        *this = other;
    }

    friend std::ostream &operator<<(std::ostream &, const Test &);
};

std::ostream &operator<<(std::ostream &out, const Test &test)
{
    out << test.id << ": " << test.name;
    return out;
}
int main()
{
    Test test1(10, "Mike");
    Test test2(20, "Bob");

    std::cout << test1 << " " << test2 << std::endl;
    return 0;
}
