// 115. 不同的子序列
// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相
// 对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
// 题目数据保证答案符合 32 位带符号整数范围。

#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution 
{
private:
    vector<vector<unsigned long long>> vec;
public:
    //s = "rabbbit", t = "rabbit"
    int mynumDistinct(string& s, string& t, int sl, int tl){
        if (sl < tl) return 0;
        if (tl == 0) return vec[sl][tl];
        if (s == t) return 1;
        for (int i = 1; i <= sl; ++i){
            for (int j=1; j <= tl; ++j){
                if (s[i-1] == t[j-1]) vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
                else vec[i][j] = vec[i-1][j];
            }
        }
        return vec[sl][tl];
    }
    int numDistinct(string s, string t) {
        //memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的。 
        //其原型是：void* memset(void *_Dst, int  _Val, size_t _Size)
        //_Dst是目标起始地址，_Val是要赋的值，_Size是要赋值的字节数。
        vec=vector<vector<unsigned long long>> (s.length()+1,vector<unsigned long long> (t.length()+1));
        for (int i=0; i<s.length()+1; ++i)
        {
            vec[i][0]=1;
        }
        return mynumDistinct(s,t,s.length(),t.length());
    }
};