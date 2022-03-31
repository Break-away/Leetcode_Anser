/*给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符*/

/*解题思路：
对于dp[i][j]，即变化字符串A的前i个元素变化至目标字符串B的前j个元素
的步数，可以通过三种方式得到：
①通过在A中添加一个字符串，则意味着A中的前i个元素可以变化至B中的前
j-1个元素，在上述基础上，在A中添加一个等于B中的第j个元素的元素即可
满足要求，故dp[i][j]= dp[i][j-1]+1；
②通过删除A中的一个字符串，则意味着A中的前i-1个元素可以变化至B中的
故dp[i][j]= dp[i-1][j]+1；
③通过修改A中的一个字符串，即在dp[i-1][j-1]的基础上，变化A中的第i个
元素到与B中的第J个字符串相同，
故dp[i][j]= dp[i-1][j-1] 或者 dp[i][j]= dp[i-1][j-1]+1；*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++) dp[0][i] = i;
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i - 1][j - 1]));
                else dp[i][j] = min(dp[i][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1));
            }
        }
        return dp[m][n];
    }
};
