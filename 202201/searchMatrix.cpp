/*编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。*/

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (target < matrix[0][0]) return false;
        int row = matrix.size() - 1, col = matrix[0].size() - 1;
        if (target > matrix[row][col]) return false;
        /*查找目标所在的行*/
        int up = 0, down = row;
        int r = row;
        while (up < down) {
            int midrow = (up + down) / 2;
            if (matrix[midrow][0] == target) {
                r = midrow;
                break;
            }
            if (matrix[midrow][0] > target) {
                r = midrow;
                down = midrow;
            }
            else {
                up = midrow + 1;
            }
        }
        /*查找结果为：目标值所在行或大于目标值的行*/
        if (matrix[r][0] > target && r > 0) r--;

        /*在目标所在行中查找是否存在目标*/
        int left = 0, right = col;
        int c = col;
        while (left < right) {
            int midcol = (left + right) / 2;
            if (matrix[r][midcol] == target) {
                c = midcol;
                break;
            }
            if (matrix[r][midcol] > target) {
                c = midcol;
                right = midcol;
            }
            else {
                left = midcol + 1;
            }
        }
        return matrix[r][c] == target;

    }
};