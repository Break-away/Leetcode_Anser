// 109. 有序链表转换二叉搜索树
// 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。



//Definition for singly-linked list.
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    //寻找链表的的中点
    ListNode* find_ln_mid(ListNode* head, ListNode* end)
    {
        ListNode* fastptr=head;
        ListNode* slowptr=head;
        while(fastptr != end && fastptr->next !=end)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next;
            fastptr=fastptr->next;
        }
        return slowptr;

    }
    TreeNode* BST(ListNode* begin, ListNode* end)
    {
        //如果begin和end相等，则表明begin和end指向的listnode已经生成root节点
        if (begin == end)
        {
            return nullptr;
        }
        ListNode* mid=find_ln_mid(begin,end);
        TreeNode* root=new TreeNode(mid->val);
        root->left=BST(begin,mid);
        root->right=BST(mid->next,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        return BST(head,nullptr);   
    }
};