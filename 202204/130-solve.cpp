// 130. 被围绕的区域
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

//解题思路：
// 查找所有被X包围的O，可以通过查找所有的O，除掉没有被X包围的即是需要的；
// 查找未被x包围的o，则o一定位于边界或者与边界的o直接或者间接相连；
// 将未被x包围的o标记为A

#include <vector>

using std::vector;

class Solution {
public:
    int row = 0;
    int column = 0;
    // 标记输入位置的O以及与其相连的O
    void dfs(vector<vector<char>> &board, int r, int c){
        //如果输入位置不是O则直接终止
        if (r<0 || c <0 || r>=row || c>= column || board[r][c] != 'O') return ;
        // 标记输入位置O及其相连的O
        board[r][c] = 'A';
        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if (row = 0) return ;
        column = board[0].size();
        //查找并标记位于边界的O
        // 位于两侧边界的O
        for (int i=0; i<row; i++){
            dfs(board,i,0);
            dfs(board,i,column-1);
        }
        // 位于上下边界的O
        for (int j=1; j<column-1; j++){
            dfs(board,0,j);
            dfs(board,row-1,j);
        }
        //将被X包围的O标记为X
        for (int i=0; i<row; i++){
            for (int j=0; j<column; j++){
                if (board[i][j] == 'X') continue;
                else if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};