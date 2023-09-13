// 164. 最大间距
// 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。
// 如果数组元素个数小于 2，则返回 0 。
// 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法

#include <vector>
#include <unordered_set>
#include <algorithm>
using std::max_element;
using std::max;
using std::unordered_set;
using std::vector;

//超时解答
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        //用hash表存储所有元素，便于访问
        unordered_set<int> num_set;
        for (int i=0; i<n; i++){
            num_set.emplace(nums[i]);
        }
        //数组元素小于2，返回0
        if (num_set.size() <= 1) return 0;
        int ans = 1;
        //从前往后遍历hash表中的所有元素
        for(unordered_set<int>::iterator begin = num_set.begin(); begin != num_set.end(); begin++){
            //如果有比当前元素大1的元素，那么最大间距肯定不会在当前元素开始
            if (num_set.count(*begin+1)) continue;
            //记录以此位置开始的最大间距，初始为1
            int temp = 1;
            //当前元素值
            int cur_num = *begin;
            //如果找不到比当前元素大1的元素，间距加1；
            while (!num_set.count(++cur_num)) {
                temp++;
            }
            ans = std::max(ans,temp);
        }
        return ans;
    }
};

// 基数排序：
// 依次排序数组中元素的个位、十位、百位至最大元素的最高位，形成有序数组：
// 1、按照数组中元素的个位进行排序，先统计个位相同的元素数量，并分配个位相同元素的位置，
//    从后往前遍历数组，再将个位相同的元素放置在一起，若个位排好序之后，个位相同的元素
//    将会位于数组中的连续位置；
// 2、再依次排序上一步排序完成后数组的十位，依然先统计十位相同的元素数量，并分配十位相同
//    元素的位置，元素上一步排好序之后，个位上数值大的元素位于后部，因此从后往前遍历数组
//    中的元素，将十位相同放置在一起时，个位较大的元素会先放到十位相同元素的分配位置的后部，
//    因此十位和个位已按照从小到大排序；
// 3、重复第2步步骤；
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int exp = 1;
        //用于存储排序过程中排好序的数组
        vector<int> buf(n);
        int maxVal = *max_element(nums.begin(), nums.end());
        // 按照个位、十位至最高位的顺序排序数组
        while (maxVal >= exp) {
            // 用于存储数组中当前位为0-9数值的元素数量
            vector<int> cnt(10);
            // 遍历数组，计算当前位为0-9数值的元素数量
            for (int i = 0; i < n; i++) {
                // 存储当前位的数值
                int digit = (nums[i] / exp) % 10;
                // 当前位数值的元素数量加1
                cnt[digit]++;
            }
            // 按照当前位数值的大小，从小到大为元素分配位置
            for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
            }
            // 从后往前遍历数值，按照当前位数值的大小进行排序
            for (int i = n - 1; i >= 0; i--) {
                //存储数组中元素的当前位数值
                int digit = (nums[i] / exp) % 10;
                //将元素根据当前位的数值，存储到指定的位置
                buf[cnt[digit] - 1] = nums[i];
                //当前元素已经占用了一个位置，将按照位数值分配的位置减1
                cnt[digit]--;
            }
            // 用排序后的数组去替换原数组
            copy(buf.begin(), buf.end(), nums.begin());
            // 遍历下一位
            exp *= 10;
        }
        // 计算排序数组中相邻元素的的最大差值，并作为结果
        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
};