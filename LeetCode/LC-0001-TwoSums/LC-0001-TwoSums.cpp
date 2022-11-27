/*
    LC 1 Two Sum

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Use a map
*/


#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>

std::vector<int> twoSum(std::vector<int>& nums, int target);


int main()
{

    while(1)
    {
        std::string line;
        std::string sum;

        std::cout << "Enter a list of numbers, e.g 1 2 3 4 5\n";
        printf("> ");
        std::getline(std::cin, line);

        std::vector<std::string> tokens;
        boost::split(tokens, line, boost::is_any_of(" "));

        std::vector<int> numbers;
        for (auto t : tokens)
            numbers.push_back(boost::lexical_cast<int>(t));

        std::cout << "Enter the sum to search for, e.g. 3\n";
        std::getline(std::cin, line);
        int target = boost::lexical_cast<int>(line);

        auto result = twoSum(numbers, target);

        printf("Result:\n");
        for (auto r : result)
            printf("%d ", r);

        printf("\n");
    }

}


std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::map<int, int> numbers_map;

    for (int n = 0; n < nums.size(); n++)
    {
        int value = nums[n];

        auto i = numbers_map.find(target - value);
        if (i != numbers_map.end())
            return { n, i->second };

        numbers_map[value] = n;
    }

    return std::vector<int>();
}



