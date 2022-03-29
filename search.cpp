using namespace std;
#include <vector>;
/*���ֲ��ң�һ��϶�����һ��϶��������м�ֵС�����Ҳ�ֵ����һ����಻һ���򣬵��Ҳ�����
���м�ֵ�������Ҳ�ֵ����һ����������Ҳ಻һ������*/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (!nums.size()) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] == target) return mid;
            /*�Ҳ�����*/
            if (nums[0] <= nums[mid])
            {
                if (target >= nums[mid + 1] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            /*�������*/
            else
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};