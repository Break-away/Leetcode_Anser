// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。
// 本题中，一棵高度平衡二叉树定义为：
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
#include <algorithm>

using std::max;

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
public:
    int treeheight(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int height=max(treeheight(root->left),treeheight(root->right))+1;
        return height;
    }
    bool isBalanced(TreeNode* root) 
    {
        return (treeheight(root->left)-treeheight(root->right))>=-1 && (treeheight(root->left)-treeheight(root->right))<=1;
    }
};