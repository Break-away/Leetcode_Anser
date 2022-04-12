// 114. 二叉树展开为链表
// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针
// 指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。

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
    void flatten(TreeNode* root) 
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        while (root->left != nullptr || root->right != nullptr)
        {
            TreeNode* temp=root;
            if (root->left != nullptr)
            {
                temp=root->left; 
                while(temp->right != nullptr)
                {
                    temp = temp->right;
                }
            }
            if (temp != root)
            {
                temp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};