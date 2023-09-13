// 112. 路径总和
// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
// 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值
// 相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
// 叶子节点 是指没有子节点的节点。
// 树中节点的数目在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000
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
    // 退出条件：root为空，返回false；root为叶子结点，返回root的val和目标值相等；
    // 符合条件：左子树到其叶子节点的路径和满足要求或者右子树到其叶子结点的路径和
    // 满足要求;
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root==nullptr) return false;
        if (root->left==nullptr && root->right==nullptr) return root->val==targetSum;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};
