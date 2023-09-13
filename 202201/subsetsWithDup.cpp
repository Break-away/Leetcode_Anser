/*给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。*/

#include <vector>;
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans{};
    vector<int> combination{};

    void dfs(bool choosepre, vector<int>& nums, int i, int n) {
        if (i == n) {
            ans.push_back(combination);
            return;
        }
        dfs(false, nums, i + 1, n);
        if (!choosepre && i > 0 && nums[i] == nums[i - 1]) return;
        combination.emplace_back(nums[i]);
        dfs(true, nums, i + 1, n);
        combination.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        dfs(false, nums, 0, len);
        return ans;
    }
};