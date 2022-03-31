#include <vector>;
#include <algorithm>;

using namespace std;

/*���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��*/
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