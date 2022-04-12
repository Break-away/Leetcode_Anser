// 124. 二叉树中的最大路径和
// 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。
// 同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
// 路径和 是路径中各节点值的总和。
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 解题思路：
// 二叉树中的最大路径肯定会经过该二叉树中的某一个节点；
// 经过那个节点时有两种情况:
// 第一种情况，经过该点和他的左右子节点；
// 第二种情况，当经过该点的某个子节点会使路径和变小，则只经过该点和他的左右子树中的某一个点；
// 定义：用节点的贡献值表示经过该点的最大路径和，如果有一条路径经过某个节点，这个节点会使路径的和加大，
// 则这个节点贡献值为正，如果会使路径和减小，则不能经过该点，则认为该节点贡献为0；
// 所以，因为一个节点的最小贡献值定义为0，所以经过某一个点的最大路径等于节点值加上左右子节点的贡献值；
// 定义一个函数计算二叉树的节点的贡献值，在计算节点贡献值的时候，也可以计算该点的最大路径和；
// 比较各个节点的最大路径和，最大值即使二叉树的最大路径和

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
private:
    int maxsum=INT_MIN;
public:
    //寻找当前节点的最大贡献值
    int maxgain(TreeNode* root){
        if (root == nullptr) return 0;
        //寻找左子树的最大贡献值，如果贡献为负数，则默认不经过该点
        int leftgain=max(0,maxgain(root->left));
        //寻找右子树的最大贡献值，如果贡献为负数，则默认不经过该点
        int rightgain=max(0,maxgain(root->right));

        //当前节点的最大路径和
        int maxpath=root->val + leftgain + rightgain;
        //比较各个节点的最大路径和
        maxsum=max(maxsum,maxpath);

        //如果存在一条路径经过该点，那么该路径只能经过该点左右子节点中的某一个
        //所以该点的最大贡献等于该点的val加上最大贡献子节点
        return root->val+max(leftgain,rightgain);
    }
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return maxsum;
    }
};