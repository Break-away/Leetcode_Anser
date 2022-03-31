/*给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。*/

/*题解：采用活动窗口，若窗口内的的字符不涵盖t，则窗口右侧继续右移，
若窗口内的字符涵盖t，则判断窗口左侧字符是否属于t中字符，若是，则更
正活动窗口内的字符数，并将左侧窗口右移*/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*创建用于存储字符串s的活动窗口和字符串t的字符数的unordered_map*/
    unordered_map<char, int> temp, strt;
    /*创建检查活动窗口是否包含字符串t中的所有字符*/
    bool check() {
        for (const auto& ch : strt) {
            if (temp[ch.first] < ch.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        /*初始化strt*/
        for (const auto& c : t) {
            ++strt[c];
        }
        int l = 0, r = -1;
        int ansL = -1, len = INT_MAX;
        while (r < (int)s.size()) {
            if (strt.find(s[++r]) != strt.end()) temp[s[r]]++;
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (strt.find(s[l]) != strt.end()) temp[s[l]]--;
                l++;
            }
        }
        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};