#include <iostream>

class Animal
{
public:
    // Pure virtual function
    // of Abstract class
    virtual void speak() = 0;
    virtual void run() = 0;
};
class Dog: public Animal
{
public:
    virtual void speak()
    {
        std::cout << "woof!" << std::endl;
    }
};

class Labrador: public Dog
{
public:
    Labrador()
    {
        std::cout << "new labrador" << std::endl;
    }
    virtual void run()
    {
        std::cout << "Labrador running" << std::endl;
    }
};

int main()
{
    Labrador labs[5];

    Labrador lab;


    Animal *animals[5];
    animals[0] = &lab;

    animals[0]->speak();
    return 0;
}
