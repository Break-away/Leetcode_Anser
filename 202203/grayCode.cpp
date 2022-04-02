// 89. 格雷编码
// n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
// 每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
// 第一个整数是 0
// 一个整数在序列中出现 不超过一次
// 每对 相邻 整数的二进制表示 恰好一位不同 ，且
// 第一个 和 最后一个 整数的二进制表示 恰好一位不同
// 给你一个整数 n ，返回任一有效的 n 位格雷码序列 。

#include <vector>
#include <cmath>
using std::vector;

class Solution {
public:
    // void graycoden(int n, vector<int> &vec)
    // {
    //     if (n==1)
    //     {
    //         vec[0]=0;
    //         vec[1]=1;
    //     }
    //     else
    //     {
    //         graycoden(n-1,vec);
    //         vector<int> vec_copy=vec;
    //         std::reverse(vec_copy.begin(),vec_copy.begin()+pow(2,n-1));
    //         for(int i=pow(2,n-1); i<pow(2,n); i++)
    //         {
    //             vec[i]=vec_copy[i-pow(2,n-1)]+(1<<(n-1));
    //         }
    //     }
    // }
    // vector<int> grayCode(int n) 
    // {
    //     int num=pow(2.0,n);
    //     vector<int> vec(num,0);
    //     graycoden(n,vec);
    //     return vec;
    // }
    // vector<int> grayCode(int n) 
    // {
    //     int num=pow(2.0,n);
    //     vector<int> vec;
    //     vec.reserve(num);
    //     vec.push_back(0);
    //     vec.push_back(1);
    //     for (int i=2; i<=n; i++)
    //     {
    //         int vecsize=vec.size();
    //         for (int j=vecsize-1; j>=0; j--)
    //         {
    //             vec.push_back(vec[j]+(1<<(i-1)));
    //         }
    //     }
    //     return vec;
    // }

    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.reserve(1 << n);
        ret.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = ret.size();
            //从后往前在元素首位加1
            for (int j = m - 1; j >= 0; j--) 
            {
                //在格雷编码的各个元素的首位加1，也是格雷编码
                ret.push_back(ret[j] | (1 << (i - 1)));
            }
        }
        return ret;
        //master和dev-第二次
    }
};
