// 200. 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。

// 解题思路：
// 定义一个变量，用于存储岛屿数量，初始值为0；
// 定义一个置0函数，用于将输入的节点以及与其相连的的状态为’1’的节点的状态变为’0’；
// 访问各个节点，如果节点的状态为’1’，调用置0函数，同时将岛屿数量加1；

#include <vector>

using std::vector;

class Solution {
public:
    //将输入节点置0，同时将与输入节点连接的'1'置为'0'
    void set_to_zero(vector<vector<char>> &grid, int r, int c){
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c] != '1'){
            return ;
        }
        grid[r][c] = '0';
        set_to_zero(grid,r-1,c);
        set_to_zero(grid,r+1,c);
        set_to_zero(grid,r,c-1);
        set_to_zero(grid,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row < 1) return 0;
        int column = grid[0].size();
        int ans = 0;
        for (int i=0; i<row; i++){
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] == '1'){
                    set_to_zero(grid,i,j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
