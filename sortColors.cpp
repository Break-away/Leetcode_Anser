/*给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对
它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝
色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。*/

#include <vector>;
#include "sortColors.h"

using namespace std;

void Solution::sortColors(vector<int>& nums)
{
    int len = nums.size();
    int p = 0, p2 = len - 1;
    for (int i = 0; i <= p2; i++) {
        while (i <= p2 && nums[i] == 2) {
            swap(nums[i], nums[p2]);
            p2--;
        }
        if (nums[i] == 0) {
            swap(nums[p], nums[i]);
            p++;
        }
    }
}