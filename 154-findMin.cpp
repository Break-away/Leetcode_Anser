// 154. 寻找旋转排序数组中的最小值 II
// 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
// 例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
// 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
// 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], 
// a[1], a[2], ..., a[n-2]] 。
// 给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形
// 进行了多次旋转。请你找出并返回数组中的 最小元素 。
// 你必须尽可能减少整个过程的操作步骤。

#include <vector>

using std::vector;

//错误解答
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            //如果只剩一个元素，直接返回
            if (left == right) return nums[left];
            //如果只剩两个元素，返回较小的那一个
            if (right == left+1) return std::min(nums[left],nums[right]);
            //从中间将数组分为两部分，至少有一部分是有序的
            int mid = left + ((right-left) >> 1);
            //如果左侧有序
            if (nums[left] <= nums[mid]){
                //最小元素位于有序部分时
                if (nums[left] <= nums[right]){
                    return nums[left];
                }
                //最小元素位于无序部分时
                else{
                    left = mid+1;
                }
            }   
            //如果右侧有序
            else{
                //最小元素位于有序部分时
                if (nums[mid-1] > nums[mid]){
                    return nums[mid];
                }
                //最小元素位于无序部分时
                else{
                    right = mid-1;
                }
            }
        }
        return 0;
    }
};

//官方解答
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];
    }
};