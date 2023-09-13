/*10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n = p.size();
        auto match = [&] (int i, int j){
            if (i==0) return false;
            if (p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };
        //f[i][j]表示s的前i个字符和p的前j个字符能否匹配
        vector<vector<int>> f(m+1, vector<int>(n+1));
        f[0][0] = true;
        for (int i=0; i<=m; i++){
            //无论s的i等于多少，若p的j等于0，则s和p肯定不匹配
            for (int j=1; j<=n; j++){
                if (p[j-1] == '*'){
                    //只要p中第j个等于*，不管s[i]和p[j-1]是否相等，则一定有如下等式
                    f[i][j] |= f[i][j-2];
                    if(match(i,j-1)){
                        f[i][j] |= f[i-1][j];
                    }
                }
                else 
                {
                    if (match(i,j)) f[i][j] = f[i-1][j-1];
                }
            }
        }
        return f[m][n];
    }
};

int main(){
    Solution s;
    string str="ab";
    string p = "a*";
    cout <<"ans:" << s.isMatch(str,p) << endl;
}