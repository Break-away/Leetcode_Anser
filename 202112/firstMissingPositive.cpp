#include <vector>;
#include <iostream>;

using namespace std;
/*给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        int ans = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) < n + 1)
            {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0) return i + 1;
        }
        return ans;
    }
};

void main()
{
    vector <int> input0{ 1,2,0 };
    Solution solution;
    int ans=solution.firstMissingPositive(input0);
    cout << "the ans is" << ans << endl;
}