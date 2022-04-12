// 116. 填充每个节点的下一个右侧节点指针
// 给定一个 完美二叉树 ，其所有叶子节点都在同一层，
// 每个父节点都有两个子节点。二叉树定义如下：
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
// 如果找不到下一个右侧节点，则将 next 指针设置为 nullptr。
// 初始状态下，所有 next 指针都被设置为 nullptr。

#include <stack>

using std::stack;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) 
    {
        if (root == nullptr) return root;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node* temp=stk.top();
            stk.pop();
            if (temp->left != nullptr)
            {
                temp->left->next = temp->right;
                stk.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                if (temp->next != nullptr)
                {
                    temp->right->next = temp->next->left;
                    stk.push(temp->right);
                }
                else
                {
                    stk.push(temp->right);
                }
            }
        }
        return root;
    }
};