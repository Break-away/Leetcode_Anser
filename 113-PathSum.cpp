// 113. 路径总和 II
// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，
// 找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
// 叶子节点 是指没有子节点的节点。
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

class Solution 
{
private:
   vector<vector<int>> ans; 
public:
    // 退出条件：
    // 如果root为空，返回空vec
    // 如果root为叶子节点，判断root的val和目标值是否相等
    // 符合条件：
    // 当前节点为叶子节点，且节点值和目标值相等，则将当前节点加入结果并返回；
    void findpath(TreeNode* root, int targetsum, vector<int> &path)
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (root->val == targetsum)
            {
                path.emplace_back(root->val);
                ans.push_back(path);
                path.pop_back();  //添加path之后需删除刚添加的元素
                return;
            }
        }
        path.emplace_back(root->val);
        if(root->left != nullptr)
        {
            findpath(root->left,targetsum-root->val,path);
        }
        if (root->right != nullptr) 
        {
            findpath(root->right,targetsum-root->val,path);
        }
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> path;
        findpath(root,targetSum,path);
        return ans;
    }
};
