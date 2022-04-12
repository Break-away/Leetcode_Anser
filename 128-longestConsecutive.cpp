// 128. 最长连续序列
// 给定一个未排序的整数数组 nums ，找出数字连续的最长
// 序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::vector;
using std::max;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); 
        if (n == 0) return 0;
        if (n == 1) return 1;
        //用于快速查找元素是否存在
        unordered_set<int> nums_set(nums.begin(), nums.end());
        //用于存储最大的序列长度
        int size=INT_MIN;
        //遍历每个元素查找以此为起点的序列
        for (int i=0; i<n; i++){
            int cur_num = nums[i];
            //如果输入中有比当前元素小1的元素，
            //那么以该元素为起点的元素一定不是最大序列，直接跳过
            if (nums_set.find(cur_num-1) == nums_set.end()){
                int length=1;
                //查找连续序列长度
                while (nums_set.find(++cur_num) != nums_set.end()){
                    length++;
                }
                size = max (size,length);
            }
        }
        return size;
    }
};