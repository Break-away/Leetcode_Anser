// 131. 分割回文串
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。
// 返回 s 所有可能的分割方案。
// 回文串 是正着读和反着读都一样的字符串。

// 解题思路：
// 用一个容器存储s所有子串是否回文串
// 然后遍历s所有子串，将属于回文字符串的字符加入结果中

#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;
using std::min;

class Solution {
private: 
    //存储子串是否是回文串
    vector<vector<int>> f;
    //存储返回结果
    vector<vector<string>> ret;
    //存储一个结果
    vector<string> ans;
public:
    void dfs(string &s, int l){
        int n = s.size();
        //如果查找位置n说明已经找到一个结果，将结果存入ret
        if (l == n) {
            ret.push_back(ans);
        }
        //从位置l开始搜索往后的各个子串
        for (int i=l; i<n; i++){
            //如果位置l到i的子串是回文串，则是我们查找的结果
            if (f[l][i]){
                ans.push_back(s.substr(l,i-l+1));
                dfs(s,i+1);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        //初始状态所有子串都默认为true
        f = vector<vector<int>>(len,vector<int>(len,true));
        //计算各个子串是否为回文子串
        for(int i= len-1; i>=0 ; i--){
            for (int j=i+1; j<=len-1; j++){
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }
        //从位置0开始搜索各个子串
        dfs(s,0);
        return ret;
    }
};

// 132. 分割回文串 II
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
// 返回符合要求的 最少分割次数 。

class Solution {
    private: 
    //存储子串是否是回文串
    vector<vector<int>> f;
    //存储子串最小分割次数
    vector<int> ans;
    
public:
    int minCut(string s) {
        int len = s.length();
        f = vector<vector<int>>(len,vector<int>(len,true));
        ans = vector<int> (len,INT_MAX);
        //计算各个子串是否为回文子串
        for(int i= len-1; i>=0 ; i--){
            for (int j=i+1; j<=len-1; j++){
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }
        //计算各个子串的最小分割次数
        for (int i=0; i<len; i++){
            if (f[0][i]) ans[i]=0;
            else{
                for (int j=i; j>0; j--){
                    if (f[j][i]){
                        ans[i] = min(ans[i],ans[j-1]+1);
                    }
                }
            }
        }
        return ans[len-1];
    }
};