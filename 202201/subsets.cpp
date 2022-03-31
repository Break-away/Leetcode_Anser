/*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。*/
#include <vector>;

using namespace std

class Solution {
public:
    vector<vector<int>> ans{ vector<int>() };
    vector<int> temp;

    void dfs(vector<int>& nums, int min, int max, int k) {
        if (max - min + 1 <= k - temp.size()) return;
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[min]);
        dfs(nums, min + 1, max, k);
        temp.pop_back();
        dfs(nums, min + 1, max, k);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            dfs(nums, 0, n, i);
        }
        return ans;
    }
};