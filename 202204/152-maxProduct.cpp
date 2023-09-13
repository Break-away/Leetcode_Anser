// 152. 乘积最大子数组
// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组
// （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
// 测试用例的答案是一个 32-位 整数。
// 子数组是数组的连续子序列。

// 解题思路：
// 从前往后遍历数组，依次计算每个子数组的乘积；
// 如果数组中的一些元素是连续的，那么他们就是一个子数组；

#include <vector>

using std::vector;

//错误解答
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //用于记录子数组最大乘积，初始值为int_min
        int sum = INT_MIN;
        //从前往后遍历每个位置的元素
        int n = nums.size();
        for (int i=0; i<n; i++){
            //先判断当前元素是否只比前一个元素大1，如果是，那么该元素已经计算过，直接跳过
            if (i>0 && nums[i] - nums[i-1] == 1) continue;
            //创建一个临时变量，用于记录当前元素为起点的子数组的乘积，初始值为1
            int cur_sum = nums[i];
            //计算子数组的累计乘积
            int j = i;
            while (nums[j+1] - nums[j] == 1)
            {
                cur_sum *= nums[++j];
            }
            //用当前子数组的乘积值和此前计算的最大乘积的较大值更新最大乘积
            sum = std::max(sum, cur_sum);
        }
        return sum;
        //返回最大乘积
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = maxF, ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = std::max(mx * nums[i], std::max(nums[i], mn * nums[i]));
            minF = std::min(mn * nums[i], std::min(nums[i], mx * nums[i]));
            ans = std::max(maxF, ans);
        }
        return ans;
    }
};