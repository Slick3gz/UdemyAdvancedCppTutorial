#include <iostream>

class Test
{

int id{3};
std::string name{"Mike"};

public:
    Test() = default;
    Test(const Test &other) = delete;
    Test(int id) : id(id) {}
    Test &operator=(const Test &other) = delete;
    void print()
    {
        std::cout << id << ": " << name << std::endl;
    }
};
int main()
{
    Test test;
    test.print();

    Test test1(77);
    test1.print();

/*     Won't work -- deleted functions
 *     Test test2(test);
 *     test2.print();
 */

/*     Test test3 = test2;
 *     test3.print();
 */
    return 0;
}
