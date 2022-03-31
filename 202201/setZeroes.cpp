/*����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��*/

#include <vector>

using namespace std;

/*�ⷨһ*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> row(r, 0), col(c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
            }
        }
    }
};

/*�ⷨ��*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int i = 0; i < r; i++) {
            if (matrix[i][0] == 0) col0 = true;
        }
        for (int i = 0; i < c; i++) {
            if (matrix[0][i] == 0) row0 = true;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = r - 1; i > 0; i--) {
            for (int j = c - 1; j > 0; j--) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if (row0) {
            for (int i = 0; i < c; i++) matrix[0][i] = 0;
        }
        if (col0) {
            for (int i = 0; i < r; i++) matrix[i][0] = 0;
        }
    }
};