// 118. 杨辉三角
// 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//1 <= numRows <= 30

#include <vector>

using std::vector;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1},{1,1}};
        ans.push_back({1});
        ans.push_back({1,1});
        for (int i=2; i<numRows; i++){
            ans.push_back({});
            for (int j=0; j<=i; j++){
                if (j == 0 || j ==i ) {
                    ans[i].push_back(1);
                }
                else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
        }
        return ans;
    }
};