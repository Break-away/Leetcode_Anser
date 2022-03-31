#include <vector>;
#include <string>;
#include <unordered_map>;

using namespace std;


/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。*/

/*该解法：效率低，计算时间长*/
class Solution {
public:
    bool match(vector<string>& strs, int i, int j)
    {
        if (strs[i].size() != strs[j].size()) return false;
        unordered_map<char, int> temp;
        for (int m = 0; m < strs[i].size(); m++)
        {
            char ch = strs[i][m];
            temp[ch]++;
        }
        for (int n = 0; n < strs[j].size(); n++)
        {
            temp[strs[j][n]]--;
        }
        for (int k = 0; k < strs[i].size(); k++)
        {
            if (temp[strs[i][k]] != 0)
                return false;
        }
        return true;

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans{};
        int n = strs.size();
        if (n == 0) return ans;
        if (n == 1)
        {
            ans.push_back({ strs[0] });
            return ans;
        }
        vector<int> used(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (used[i] == 1) continue;
            vector<string> comb;
            comb.push_back(strs[i]);
            for (int j = i + 1; j < n; j++)
            {
                if (match(strs, i, j))
                {
                    comb.push_back(strs[j]);
                    used[j] = 1;
                }
            }
            ans.push_back(comb);
        }
        return ans;
    }
};