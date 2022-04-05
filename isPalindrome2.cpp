// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，
// 可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::reverse_copy;

class Solution {
public:
    //运用标准库；
    bool isPalindrome(string s) {
        int length=s.length();
        vector<char> vec;
        for (int i=0; i<length; ++i)
        {
            if (isalnum(s[i])) vec.push_back(tolower(s[i]));
        }
        vector<char> vec_copy(vec.size());
        reverse_copy(vec.begin(),vec.end(),vec_copy.begin());
        return vec==vec_copy;
    }
    //双指针
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;
        while (l < r){
            while (l<r && !isalnum(s[l])) ++l;
            while (l<r && !isalnum(s[r])) --r;
            if (l<r)
            {
                if (tolower(s[l]) != towlower(s[r])) return false;
                ++l;
                --r;
            }
        }
        return true;
    }

};