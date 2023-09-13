// 169. 多数元素
// 给定一个大小为 n 的数组，找到其中的多数元素。
// 多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        unordered_map<int,int> num_map;
        for (int i=0; i<n;i++){
            if (num_map.find(nums[i]) != num_map.end()){
                num_map[nums[i]]++;
                if (num_map[nums[i]] > n/2) return nums[i];
            }
            else{
                num_map[nums[i]] = 1;
            }
        }
        return 0;
    }
};