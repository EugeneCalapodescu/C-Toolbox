/* 

LC-1768-MergeStringsAlternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.


Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s

*/

#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    auto i1 = word1.begin();
    auto i2 = word2.begin();
    
    int turn = 0;

    string res;
    while (i1 != word1.end() || i2 != word2.end())
    {
        turn = 1 - turn;
        if (turn == 1 && i1 != word1.end())
            res.push_back(*i1++);
        else if(turn == 0 && i2 != word2.end())
            res.push_back(*i2++);
    }

    return res;
}

int main()
{
    std::cout << "ABC abc => " << mergeAlternately("ABC", "abc") << "\n";
    std::cout << "A   abc => " << mergeAlternately("A", "abc") << "\n";
    std::cout << "ABC a   => " << mergeAlternately("ABC", "a") << "\n";
    std::cout << "ABC     => " << mergeAlternately("ABC", "") << "\n";
}

