#include <vector>;
using namespace std;

class Solution {
public:
    int row[9][9];
    int column[9][9];
    int box[3][3][9];
    int valid;
    vector<pair<int, int>> spaces;

    void trackback(vector<vector<char>>& board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        auto [r, c] = spaces[pos];
        for (int n = 0; n < 9 && !valid; n++)
        {
            if (!row[r][n] && !column[c][n] && !box[r / 3][c / 3][n])
            {
                row[r][n] = column[c][n] = box[r / 3][c / 3][n] = 1;
                board[r][c] = n + '0' + 1;
                trackback(board, pos + 1);
                row[r][n] = column[c][n] = box[r / 3][c / 3][n] = 0;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        memset(box, 0, sizeof(box));
        valid = false;
        for (int i = 0; i< board.size(); i++)
        {
            for (int j = 0; j< board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    int index = board[i][j] - '0' - 1;
                    row[i][index] = column[j][index] = box[i / 3][j / 3][index] = 1;
                }
            }
        }
        trackback(board, 0);
    }
};

class Solution {
public:
    int row[9][9];
    int column[9][9];
    int box[3][3][9];

    void trackback(vector<vector<char>>& board, int r, int c)
    {
        if (board[r][c] != '.')
        {
            int index = board[r][c] - '0' - 1;
            ++row[r][index];
            ++column[c][index];
            ++box[r / 3][c / 3][index];
            if (r < 9 && c < 8) trackback(board, r, c + 1);
            if (r < 8 && c == 8) trackback(board, r + 1, c);
            if (r == 8 && c == 8) return;
        }
        else
        {
            for (int n = 0; n < 9; n++)
            {
                if (row[r][n] < 1 && column[c][n] < 1 && box[r / 3][c / 3][n] < 1)
                {
                    ++row[r][n];
                    ++column[c][n];
                    ++box[r / 3][c / 3][n];
                }
                if (r < 9 && c < 8) trackback(board, r, c + 1);
                if (r < 8 && c == 8) trackback(board, r + 1, c);
                if (r == 8 && c == 8) return;
                --row[r][n];
                --column[c][n];
                --box[r / 3][c / 3][n];

            }
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        memset(box, 0, sizeof(box));

        trackback(board, 0, 0);
    }
};