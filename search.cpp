using namespace std;
#include <vector>;
/*二分查找，一侧肯定有序，一侧肯定无序，若中间值小于最右侧值，则一定左侧不一定序，但右侧有序，
若中间值大于最右侧值，则一定左侧有序，右侧不一定无序*/
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
            /*右侧有序*/
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
            /*左侧有序*/
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