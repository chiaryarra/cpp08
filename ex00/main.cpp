#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::cout << *easyfind(v, 20) << std::endl;
        std::cout << *easyfind(v, 99) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}