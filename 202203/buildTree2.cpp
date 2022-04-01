// 106. 从中序与后序遍历序列构造二叉树
// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的
// 中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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
private:
    int post_index;
    unordered_map<int,int> inorder_index; //存放inorder数组中元素和位置的映射
public:
    TreeNode* bulidtree_helper(int left_index, int right_index, vector<int> & inorder, vector<int>& postorder)
    {
        //当左侧位置大于右侧位置即退出循环
        if (left_index>right_index)
        {
            return nullptr;
        }
        //当左右位置相等时即终止循环
        if (left_index==right_index)
        {
            TreeNode* root_treenode = new TreeNode(postorder[post_index]);
            post_index--;  //创建当前节点后，需将post_index调整为下一节点的val
            return root_treenode;
        }
        //寻找当前root节点在inorder数组中的位置
        int inorder_root_index=inorder_index[postorder[post_index]];
        //创建当前root节点
        TreeNode* root = new TreeNode(postorder[post_index]);
        //post_index需调整为下一节点的值
        post_index--;
        //寻找当前root节点的右子树
        root->right = bulidtree_helper(inorder_root_index+1,right_index,inorder,postorder);
        //寻找当前root节点的左子树
        root->left = bulidtree_helper(left_index,inorder_root_index-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        post_index=postorder.size()-1;
        int vec_size=postorder.size();
        //创建inorder数组元素与位置的映射
        int ele_index=0;
        for (auto &inorder_ele : inorder)
        {
            inorder_index[inorder_ele]=ele_index++;
        } 
        return bulidtree_helper(0,vec_size-1,inorder,postorder);
    }
};