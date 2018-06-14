#include <iostream>


struct Test
{
   virtual bool operator()(std::string &text) = 0;
};
struct MatchTest: public Test
{
    virtual bool operator()(std::string &text)
    {
        return text == "lion";
    }
};

void check(std::string text, Test &test)
{
    if(test(text))
    {
        std::cout << "Text matches!" << std::endl;
    }
    else
    {
        std::cout << "No match." << std::endl;
    }
}

int main()
{
    MatchTest pred;

    std::string value = "lion";

    std::cout << pred(value) << std::endl;

    MatchTest m;
    check("lion", m);
    return 0;
}
