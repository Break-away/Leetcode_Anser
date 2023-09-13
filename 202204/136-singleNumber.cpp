// 136. 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素
// 均出现两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        int ans=0;
        for (int i=0; i<nums.size(); i++){
            if (hash_map.find(nums[i]) == hash_map.end()){
                hash_map[nums[i]] = 1;
            }
            else hash_map[nums[i]]++;
        }
        for (int i=0; i<nums.size(); i++){
            if (hash_map[nums[i]] == 1) {
                ans=nums[i];
            }
        }
        return ans;
    }
    // int singleNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 1) return nums[0];
    //     std::sort(nums.begin(),nums.end());
    //     int ans=0;
    //     for (int i=1; i<n-1; i++ ){
    //         if (i == 1 && nums[i] != nums[i-1]) return nums[0];
    //         else if (i == n-2 && nums[i] != nums[i+1]) return nums[i-1];
    //         else if (nums[i] != nums[i-1] && nums[i] != nums[i+1]){
    //             ans = nums[i];
    //             return ans;
    //         }
    //     }
    //     return ans;
    // }

    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

// 137. 只出现一次的数字 II
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，
// 其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        int ans=0;
        for (int i=0; i<nums.size(); i++){
            if (hash_map.find(nums[i]) == hash_map.end()){
                hash_map[nums[i]] = 1;
            }
            else hash_map[nums[i]]++;
        }
        for (int i=0; i<nums.size(); i++){
            if (hash_map[nums[i]] == 1) {
                ans=nums[i];
            }
        }
        return ans;
    }
};