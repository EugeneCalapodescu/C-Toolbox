/* LC-0271-EncodeAndDecodeStrings

String Encode and Decode

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Example 1:
    Input: ["neet","code","love","you"]
    Output:["neet","code","love","you"]

Example 2:
    Input: ["we","say",":","yes"]
    Output: ["we","say",":","yes"]

*/

#include <iostream>
#include <vector>

using namespace std;

string encode(vector<string>& strs) {
    string res;

    for (string s : strs)
    {
        if (!res.empty())
            res += '#';
        for (char c : s)
        {
            if (c == '#')
                res += '\\';
            res += c;
        }
    }
    return res;
}

vector<string> decode(string s) 
{
    vector<string> res;

    string word;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            res.push_back(word);
            word = "";
            continue;
        }

        if (s[i] == '\\' && i < s.size() - 2 && s[i + 1] == '#')
            i += 2;

        word += s[i];
    }
    if (!word.empty())
        res.push_back(word);

    return res;
}

string print(vector<string>& v)
{
    string res = "[";
    for (auto s : v)
        res += s + " ";
    return res + "]";
}

int main()
{
    vector<string> v = { "a", "#b", "c" };
    string s = encode(v);

    vector<string> res = decode(s);
    std::cout << s << "\n";
    std::cout << print(res) << "\n";

    v = { "we", "say", ":", "yes" };
    s = encode(v);
    res = decode(s);
    std::cout << s << "\n";
    std::cout << print(res) << "\n";
}

