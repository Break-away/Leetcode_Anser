/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 
存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格
是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(int i, int j, int k, string word, vector<vector<char>>& board, vector<vector<int>>& visited) {
        if (board[i][j] == word[k]) {
            if (k == word.size() - 1) return true;
            visited[i][j] = true;
            vector<pair<int, int>> nexts{ {-1,0},{1,0},{0,-1},{0,1} };
            for (auto& next : nexts) {
                int r = i + next.first, c = j + next.second;
                if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && !visited[r][c]) {
                    if (dfs(r, c, k + 1, word, board, visited)) return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, 0, word, board, visited)) return true;
            }
        }
        return false;
    }
};