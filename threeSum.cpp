using namespace std;
#include <vector>;
#include <algorithm>;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int L = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < L - 2; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int target = -nums[first];
            int three = L - 1;
            for (int second = first + 1; second < L - 1; second++)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                while (three > second && nums[second] + nums[three] > target)
                {
                    three -= 1;
                }
                if (second == three)
                {
                    break;
                }
                if (nums[second] + nums[three] == target)
                {
                    ans.push_back({ nums[first],nums[second],nums[three] });
                }
            }
        }
        return ans;
    }
};
