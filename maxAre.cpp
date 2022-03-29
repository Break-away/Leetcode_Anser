#include <vector>;
#include <algorithm>;
using namespace std;


class Solution 
{
public:
    int maxArea(vector<int>& height)
    {
        int ans = INT_MIN;
        int l = 0;
        int r = height.size() - 1;
        while (r > l)
        {
            int res = min(height[l], height[r]) * (r - l);
            if (res > ans)
            {
                ans = res;
            }
            if (height[l] < height[r])
            {
                l += 1;
            }
            else
            {
                r -= 1;
            }
        }
        return ans;
    }
};