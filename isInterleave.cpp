// 97. 交错字符串
// 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
// 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
// 注意：a + b 意味着字符串 a 和 b 连接。

#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution 
{
//错误解答
// private:
//     unordered_map<char,int> charmap;
// public:
//     void storechar(string s)
//     {
//         for (int i=0; i<s.length(); i++)
//         {
//             if (charmap.find(s[i]) != charmap.end())
//             {
//                 charmap[s[i]]+=1;
//             }
//             else
//             {
//                 charmap.emplace(s[i],1);
//             }
//         }
//     }
//     void verifychar(string s)
//     {
//         for (int i=0; i<s.size(); i++)
//         {
//             if (charmap.find(s[i]) != charmap.end())
//             {
//                 if (charmap[s[i]]=1) charmap.erase(s[i]);
//                 else charmap[s[i]]-=1;
//             }
//         }
//     }
//     bool isInterleave(string s1, string s2, string s3) 
//     {
//         //如果s1+s2的长度不等于s3的长度，则s3一定不是由s1和s2的组成的；
//         if (s1.length()+s2.length() != s3.length()) return false;
//         storechar(s3);
//         verifychar(s1);
//         verifychar(s2);
//         return charmap.empty();
//     }
    bool isInterleave(string s1, string s2, string s3) 
    {
        //如果s1+s2的长度不等于s3的长度，则s3一定不是由s1和s2的组成的；
        if (s1.length()+s2.length() != s3.length()) return false;
        auto f=vector<vector<int>> (s1.length()+1,vector<int>(s2.length()+1,false));
        f[0][0]=true;
        int l1=s1.length(),l2=s2.length(),l3=s3.length();
        for (int i=0; i<=l1; i++)
        {
            for (int j=0;j<=l2;j++)
            {
                //如果s1的第i个元素和s3的第p个元素相等，那么s1的前i个元素和s2的
                //前j个元素能否交错组成s3的前p个元素，就取决于s1的前i-1个元素和
                //s2的前j个元素能否交错组成s3的前p-1个元素；
                if (i>0)
                {
                    f[i][j] |= (f[i-1][j] && s1[i-1]==s3[i+j-1]);
                }
                if (j>0)
                {
                    f[i][j] |= (f[i][j-1] && s2[j-1]==s3[i+j-1]);
                }
                
            }
        }
        return f[l1][l2];
    }
};