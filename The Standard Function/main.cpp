#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

bool check(std::string &test)
{
    return test.size() == 5;
}

class Check {
public:
    bool operator()(std::string &test)
    {
        return test.size() == 5;
    }
} check1;

void run(std::function<bool(std::string&)> check)
{
    std::string test = "stars";
    std::cout << check(test) << std::endl;
}
int main()
{
    unsigned int size = 5;

    std::vector<std::string> vec{"one", "two", "three"};

    auto lambda = [size](std::string test){ return test.size() == size; };
    int count = count_if(vec.begin(), vec.end(), lambda);

    std::cout << count << std::endl;

    count = count_if(vec.begin(), vec.end(),check1);
    std::cout << count << std::endl;


    run(check);

    std::function<int(int, int)> add = [](int one, int two){ return one + two;};
    std::cout << add(7, 3);

    return 0;
}
