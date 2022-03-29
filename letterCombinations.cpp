using namespace std;
#include <vector>;
#include <string>;
#include <unordered_map>;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combinations;
        string combination;
        if (digits.empty()) return combinations;
        int len = digits.size();
        unordered_map<char, string> numbermap
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        backtrack(combinations, combination, digits, 0, numbermap);
        return combinations;
    }
    void backtrack(vector<string> combinations, string combination, string digits, int index, unordered_map<char, string> numbermap)
    {
        if (digits.length() == index)
        {
            combinations.push_back(combination);
        }
        else
        {
            char digit = digits[index];
            string letters = numbermap.at(digit);
            for (char letter : letters)
            {
                combination.push_back(letter);
                backtrack(combinations, combination, digits, index + 1, numbermap);
                combination.pop_back();
            }
        }
    }
};