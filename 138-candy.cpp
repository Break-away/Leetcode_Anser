// 135. 分发糖果
// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
// 你需要按照以下要求，给这些孩子分发糖果：
// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

// 解题思路：
// 左规则：如果左边的孩子分数低于右边的孩子，那么他的糖果少于右边的孩子，
// 如果右边的孩子分数低于左边的孩子，右边的孩子拿一个糖果；
// 右规则：如果右边的孩子分数低于左边的孩子，那么他的糖果少于左边的孩子，
// 如果左边的孩子分数低于右边的孩子，左边的孩子拿一个糖果；

// 结果分析：
// 按照左右规则执行后，从左至右，分数升序中，孩子按照左规则拿的糖果数量是正确的，
// 此时对应于右规则是降序，孩子拿的糖果数量都是1，分数降序中，孩子按照左规则拿到
// 的糖果数量都是1，此时右规则是升序，孩子拿到的糖果数量是正确的。
// 所以需要将左右规则的结果综合，从左至右，升序采用左规则的结果，降序采用右规则的结果；
// 针对既是位于升序也是位于降序的位置，直接取最大值即可；

#include <vector>
#include <algorithm>

using std::max;
using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //孩子数量
        int n=ratings.size();
        //用于存储左规则计算的结果
        vector<int> left(n,0);
        //用于存储计算结果
        int ret = 0;
        //左规则计算
        for (int i=0; i<n; i++){
            //如果从左往右分数为增序，孩子拿到的糖果逐渐增加
            if (i>0 && ratings[i]>ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            //如果开始出现降序，糖果数量为1
            else {
                left[i] = 1;
            }
        }
        //用于存储各个位置的分数
        int right = 0;
        //右规则计算
        for (int  j = n-1; j >= 0; j--)
        {
            //从右往左遍历如果分数为增序，孩子拿到的糖果逐渐增加
            if (j < n-1 && ratings[j] > ratings[j+1]){
                right = right + 1;
            }
            //如果开始出现降序，糖果数量为1
            else {
                right = 1;
            }
            //计算结果
            ret += max(left[j],right);
        }
        return ret;
    }
};
