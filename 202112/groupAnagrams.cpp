#include <vector>;
#include <string>;
#include <unordered_map>;

using namespace std;


/*����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�*/

/*�ýⷨ��Ч�ʵͣ�����ʱ�䳤*/
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