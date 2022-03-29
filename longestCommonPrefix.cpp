#include <string>;
#include <vector>;

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        int L = strs.size();
        int ansL = INT_MAX;
        int ans;
        for (int i = 0; i < L; i++)
        {

            if (strs[i].size() < ansL)
            {
                ansL = strs[i].size();
                ans = i;
            }
        }
        for (int j = 0; j <= ansL; j++)
        {
            for (int i = 0; i < L; i++)
            {

                if (strs[i][j] != strs[ans][j])
                {
                    return strs[ans].substr(0, j);
                }
            }
        }
        return strs[ans];
    }
};