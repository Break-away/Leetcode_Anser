/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。*/

#include <vector>;

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 0) return 0;
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1) f[i] = 1;
            else if (i == 2) f[i] = 2;
            else f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};