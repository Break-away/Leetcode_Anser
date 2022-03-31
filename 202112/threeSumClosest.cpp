using namespace std;
#include <vector>;
#include <algorithm>;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int ans = 1e7;
        sort(nums.begin(), nums.end());
        int L = nums.size();
        auto update = [&](int cur)
        {
            if (abs(cur - target) < abs(ans - target))
            {
                ans = cur;
            }
        };
        for (int first = 0; first < L; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1;
            int third = L - 1;
            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target)
                {
                    return target;
                }
                update(sum);
                if (sum > target)
                {
                    while (second < third - 1 && nums[third - 1] == nums[third])
                    {
                        third--;
                    }
                    third--;
                }
                else
                {
                    while (second + 1 < third && nums[second] == nums[second + 1])
                    {
                        second++;
                    }
                    second++;
                }
            }
        }
        return ans;
    }
};