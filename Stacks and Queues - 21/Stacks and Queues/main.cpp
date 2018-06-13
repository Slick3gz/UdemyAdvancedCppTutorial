#include <iostream>
#include <stack>
#include <queue>

class Test
{
private:
    std::string name;

public:
    Test(std::string name): name(name)
    {

    }
    ~Test()
    {
        //std::cout << "Object " << name << " destroyed" << std::endl;
    }

    void print()
    {
        std::cout << name << std::endl;
    }
};

int main()
{
    // FIFO
    std::queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    std::cout << "<------------------------------>" << std::endl;
    /*
        ----> This is invalid code <----
        Test &test1 = testStack.top();
        testStack.pop();
        test1.print(); // Reference refers to destroyed object
    */

    while(testQueue.size() > 0)
    {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }
    std::cout << "<------------------------------>" << std::endl;

    testQueue.back().print();

    return 0;
}
