#include <vector>;
#include <algorithm>;

using namespace std;

/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。*/
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int n = height.size();
        if (n < 3) return ans;
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        while (left < right)
        {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if (height[left] < height[right])
            {
                ans += leftmax - height[left];
                left++;
            }
            else
            {
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};