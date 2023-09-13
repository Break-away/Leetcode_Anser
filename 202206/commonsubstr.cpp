/*描述
给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。

注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。
数据范围：字符串长度：1\le s\le 150\1≤s≤150 
进阶：时间复杂度：O(n^3)\O(n 3 ) ，空间复杂度：O(n)\O(n) 
输入描述：
输入两个只包含小写字母的字符串

输出描述：
输出一个整数，代表最大公共子串的长度*/

#include <bits/stdc++.h>

using namespace std;

int check(const string& str1, const string& str2){
    int m = str1.length(), n = str2.length();
    int max_len = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            if (dp[i][j] > max_len) max_len = dp[i][j];
        }
    }
    return max_len;
}

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        if (str1.size() < str2.size()) swap(str1,str2);
        cout << check(str1,str2) << endl;
    }
    return 0;
}