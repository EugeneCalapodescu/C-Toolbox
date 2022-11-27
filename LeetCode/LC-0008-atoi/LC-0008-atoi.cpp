/*

LC-8 Atoi

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.


*/



#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>


int myAtoi(std::string s) 
{
    int i = 0;
    long long result = 0;

    // strip left spaces
    while (s[i] == ' ' && i < s.size())
        i++;

    // just spaces
    if (i >= s.size())
        return 0;

    int sign = 1;
    
    // -xxx
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    while (i < s.size())
    {
        if (!isdigit(s[i]))
            return (int)(sign * result);

        result = 10 * result + (s[i] - '0');

        int imin = INT_MIN;
        int imax = INT_MAX;

        if (sign * result > INT_MAX)
            return INT_MAX;
        else if (sign * result < INT_MIN)
            return INT_MIN;

        i++;
    }

    if (sign * result > INT_MAX)
        return INT_MAX;
    else if (sign * result < INT_MIN)
        return INT_MIN;

    return (int)(sign * result);
}

int main()
{

    while (1)
    {
        std::string line;
        std::string sum;

        std::cout << "Enter an integer, e.g. '   000-123'\n";
        printf("> ");
        std::getline(std::cin, line);

        int n = myAtoi(line);
        printf("%d\n", n);
    }

}