// 198. 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，
// 一夜之内能够偷窃到的最高金额。

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int num = nums.size();
        if (num < 1) return 0;
        if (num == 1) return nums[0];
        // 在某一个位置最大收益，取决于盗窃还是不盗窃前一户人家对当前的收益有利
        vector<int> rob_sum(num,0);
        rob_sum[0] = nums[0];
        rob_sum[1] = max(nums[1],nums[0]);
        for (int i=2; i < num; i++){
            //当前位置的最大收益
            rob_sum[i] = max(rob_sum[i-1],rob_sum[i-2]+nums[i]);
        }
        return rob_sum[num-1];
    }
};