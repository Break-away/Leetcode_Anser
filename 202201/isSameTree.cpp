
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        else if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
            return false;
        }
    }
};

class Solution {
public:
    bool Symmetric(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr) return false;
        if (l->val != r->val) return false;
        else return Symmetric(l->left, r->right) && Symmetric(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else return Symmetric(root->left, root->right);
    }
};