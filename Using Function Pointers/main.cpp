#include <iostream>
#include <algorithm>
#include <vector>

bool match(std::string test)
{
    return test == "two";
    //return test.size() == 3;
}

int countStrings(std::vector<std::string> &texts, bool (*match)(std::string test))
{
    int count = 0;
    for(std::vector<std::string>::iterator it=texts.begin(); it != texts.end(); it++)
    {
        if(match(*it))
            ++count;
    }
    return count;
}
int main()
{
    std::vector<std::string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    std::cout << match("two") << std::endl;
    std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;

    std::cout << countStrings(texts, match) << std::endl;
    return 0;
}
