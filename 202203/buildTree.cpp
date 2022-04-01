// 105. 从前序与中序遍历序列构造二叉树
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
// inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder 和 inorder 均 无重复 元素
// inorder 均出现在 preorder
// preorder 保证 为二叉树的前序遍历序列
// inorder 保证 为二叉树的中序遍历序列

#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.size()==0)
        {
            return nullptr;
        }
        //循环退出条件
        if (preorder.size()==1)
        {
            TreeNode *root_treenode=new TreeNode(preorder[0]);
            return root_treenode;
        }
        vector<int> left_preoder,left_inorder,right_preoder,right_inoder;
        //创建左子树的中序遍历数组
        for (int i=0; i<inorder.size() && inorder[i] != preorder[0]; i++)
        {
            left_inorder.push_back(inorder[i]);
        }
        //创建左子树的前序遍历数组
        for (int j=1; j<left_inorder.size()+1; ++j)
        {
            left_preoder.push_back(preorder[j]);
        }
        //创建右子树的中序遍历数组
        for (int m=left_inorder.size()+1; m<inorder.size(); m++)
        {
            right_inoder.push_back(inorder[m]);
        }
        //创建右子树的前序遍历数组
        for (int n=left_preoder.size()+1; n<preorder.size(); n++)
        {
            right_preoder.push_back(preorder[n]);
        }
        TreeNode *root=new TreeNode(preorder[0]);  //定义指针一定要赋初值
        root->left = buildTree(left_preoder,left_inorder);
        root->right = buildTree(right_preoder,right_inoder);
        return root;
    }
    //解答此题出现的几个错误：
    // 1、返回临时变量的地址；
    // 2、new运算符用法错误；
    // 3、从函数中返回指向局部变量的指针，导致指针变成空指针
    // 4、数组使用前未检查是否越界
};