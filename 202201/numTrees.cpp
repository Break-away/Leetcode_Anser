/*给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互
不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。*/

#include <vector>

using namespace std;

class Solution {
public:

    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};