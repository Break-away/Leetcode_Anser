// 129. 求根节点到叶节点数字之和
// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：
// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。

#include <vector>

using std::vector;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int sum=0;
public:
    //回溯算法
    //计算vector<int>中的元素组成的数字
    int vecsum(vector<int> &vec){
        int sum=0;
        for (int i=0; i<vec.size(); ++i){
            sum = sum*10 + vec[i];
        }
        return sum;
    }
    void mysum(TreeNode* root, vector<int> &vec){
        if (!root) return ;
        //如果为叶子节点，则计算该条路径组成的数字
        if (!root->left && !root->right){
            vec.push_back(root->val);
            sum += vecsum(vec);
            vec.pop_back();
            return ;
        }
        //如果为中间节点，则将节点的val放进vec中
        vec.push_back(root->val);
        if (root->left) mysum(root->left, vec);
        if (root->right) mysum(root->right, vec);
        //回溯
        vec.pop_back();
        return ;
    }
    int sumNumbers(TreeNode* root) {
        //vec存放一条路径中的各节点val
        vector<int> vec;
        mysum(root,vec);
        return sum;
    }
};