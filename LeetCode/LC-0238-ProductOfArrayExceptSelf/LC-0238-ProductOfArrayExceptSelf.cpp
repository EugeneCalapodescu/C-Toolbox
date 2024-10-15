/* LC - 0238 - ProductOfArrayExceptSelf

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

Compute an array with the product of the numbers before i
Compute an array with the product of the numbers after i
The result is the product of the two

Note: 
    vector initialization

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int> before(nums.size(), 1);
    vector<int> after(nums.size(), 1);

    for (int i = 1; i < nums.size(); i++)
        before[i] = before[i - 1] * nums[i - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
        after[i] = after[i + 1] * nums[i + 1];

    vector<int> res(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++)
        res[i] *= before[i] * after[i];

    return res;
}

string print(vector<int>& v)
{
    string res = "[";
    for (int n : v)
        res += std::to_string(n) + " ";
    return res + "]";
}

int main()
{
    vector<int> v = { 1, 2, 3, 4 };
    auto res = productExceptSelf(v);
    std::cout << print(v) << " " << print(res) << "\n";
}
