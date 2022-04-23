// 215. 数组中的第K个最大元素
// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

class Solution {
public:
    static bool compare(int a, int b){
        return a>=b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1 && k==1) return nums[0]; 
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }
};