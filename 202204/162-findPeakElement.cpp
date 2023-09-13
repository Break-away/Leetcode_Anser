// 162. 寻找峰值
// 峰值元素是指其值严格大于左右相邻值的元素。
// 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，
// 在这种情况下，返回 任何一个峰值 所在位置即可。
// 你可以假设 nums[-1] = nums[n] = -∞ 。
// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

#include <vector>
#include <utility>
using std::pair;
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //get是指向函数的指针
        auto get = [&] (int i) -> pair<int,int>{
            if (i == -1 || i == n) return {0,0};
            else return {1,nums[i]};
        };
        int left = 0;
        int right = n-1;
        int ans = -1;
        while (left <= right){
            int mid = left + ((right - left) >> 1);
            //如果位置mid的元素大于left和right，即是我们寻找的值
            if (get(mid)>get(mid-1) && get(mid)>get(mid+1))
            {
                ans = mid;
                break;
            }
            //如果位置mid的元素小于mid+1，那么一定有峰值出现在mid-right之间
            else if(get(mid) < get(mid+1)) left = mid+1;
            //如果位置mid的元素小于mid-1，那么一定有峰值出现在left-mid之间
            else right = mid-1;
        }
        return ans;
    }
};