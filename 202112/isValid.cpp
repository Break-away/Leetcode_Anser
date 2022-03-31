#include <unordered_map>;
#include <stack>;
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        unordered_map<char, char> symbolmap =
        {
            {')','('},
            {']','['},
            {'}','{'},
        };
        int L = s.length();
        if (L % 2 == 1)
        {
            return false;
        }
        for (int i = 0; i < L; i++)
        {
            if (symbolmap[s[i]] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if (symbolmap[s[i]] != stk.top() && stk.empty())
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};