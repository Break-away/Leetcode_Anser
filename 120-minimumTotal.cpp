// 120. 三角形最小路径和
// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的
// 是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 
// 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步
// 可以移动到下一行的下标 i 或 i + 1 。

#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::min_element;

class Solution {
//超时解答
// private:
//     int minimum=INT_MAX;
// public:
//     void dfs(vector<vector<int>>& triangle, int row, int column, int total){
//         if (row == triangle.size()) {
//             minimum = min(minimum, total);
//             return;
//         }
//         dfs(triangle,row+1,column,total+triangle[row][column]);
//         dfs(triangle,row+1,column+1,total+triangle[row][column]);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int size=triangle.size();
//         dfs(triangle,0,0,0);
//         return minimum;
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<vector<int>> f(size,vector<int>(size));
        f[0][0] = triangle[0][0];
        for (int i=1; i<size; ++i)
        {
            f[i][0] = f[i-1][0] + triangle[i][0];
            for (int j=1; j<i; ++j)
            {
                f[i][j]=min(f[i-1][j],f[i-1][j-1]) + triangle[i][j];
            }
            f[i][i] = f[i-1][i-1]+triangle[i][i];
        }
        //std::min_element 用于寻找范围 [first, last) 中的最小元素。
        // 前2个参数指定容器的范围，第3个参数是比较函数，为可选参数。
        // 返回值为指向范围 [first, last) 中最小元素的迭代器。
        // 若范围中有多个元素等价于最小元素，则返回指向首个这种元素的迭代器。若范围为空则返回 last 。
        return *min_element(f[size-1].begin(),f[size-1].end());
    }
};