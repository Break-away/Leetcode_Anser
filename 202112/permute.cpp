#include <vector>;
using namespace std;

class Solution {
public:
    void trackback(vector<int>& nums, int pos, vector<vector<int>> ans, vector<int> combination)
    {
        if (pos == nums.size())
        {
            ans.push_back(combination);
            return;
        }
        for (int i = pos; pos < nums.size(); i++)
        {
            combination.push_back(nums[i]);
            if (i != pos) swap(nums[i], nums[pos]);
            trackback(nums, pos + 1, ans, combination);
            combination.pop_back();
            if (i != pos) swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> combination;
        trackback(nums, 0, ans, combination);
        return ans;
    }
};