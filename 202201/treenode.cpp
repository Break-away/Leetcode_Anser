/*给定一个二叉树的根节点 root ，返回它的 中序 遍历。*/

#include <vector>
#include <stack>

using namespace std;

/*二叉树结构体*/
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 /*中序遍历：递归*/
class Solution {
public:
    void midtravel(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        midtravel(root->left, ans);
        ans.push_back(root->val);
        midtravel(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        midtravel(root, res);
        return res;
    }
};


/*中序遍历：迭代*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            TreeNode* top = stk.top();
            stk.pop();
            res.push_back(top->val);
            root = top->left;
        }

        return res;
    }
};

/*前序遍历：递归*/
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

/*前序遍历：迭代*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return ans;
    }
};

/*后序遍历：递归*/
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.emplace(ans.end(), root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

/*后序遍历：迭代*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* pre;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (!root->right || root->right == pre) {
                ans.emplace(ans.end(), root->val);
                pre = root;
                root = nullptr;
            }
            else {
                stk.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};
