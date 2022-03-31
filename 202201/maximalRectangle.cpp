/*给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。*/

#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0, row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> width(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') width[i][j] = (j == 0 ? 1 : width[i][j - 1] + 1);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') continue;
                else {
                    int k = i;
                    int wid = width[i][j];
                    while (k >= 0 && matrix[k][j] > 0) {
                        wid = min(wid, width[k][j]);
                        ans = max(ans, (i - k + 1) * wid);
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};