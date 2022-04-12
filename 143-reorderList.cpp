// 143. 重排链表
// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
// L0 → L1 → … → Ln - 1 → Ln
// 请将其重新排列后变为：
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
#include <vector>

using std::vector;
using std::pair;

//Definition for singly-linked list.
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    //寻找给定链表的中点
    pair<ListNode*,ListNode*> middle_node(ListNode* &head){
        ListNode* slow_ptr=head;
        ListNode* fast_ptr=head;
        while (fast_ptr && fast_ptr->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        ListNode* temp = head;
        while (temp && temp->next != slow_ptr){
            temp = temp->next;
        }
        temp->next =nullptr;
        return {head,slow_ptr};
    }
    //原地反转链表；
    void reverse_listnode(ListNode* &head){
        ListNode* temp=head;
        vector<ListNode*> vec;
        while (temp){
            vec.push_back(temp);
            temp=temp->next;
        }
        head = vec.back();
        int l = vec.size();
        for (int i=l-1; i>0; --i){
            vec[i]->next = vec[i-1];
        }
        vec[0]->next = nullptr;
    }
    //合并链表
    ListNode* merge_listnode(ListNode* first, ListNode* second){
        ListNode* head = new ListNode(0);
        ListNode* dummy=head;
        while (first && second){
            head->next = first;
            first = first->next;
            head = head->next;
            head->next = second;
            second = second->next;
            head = head->next;
        }
        if (second) head->next = second;
        return dummy->next;
    }
    void reorderList(ListNode* head) {
        if (!head->next) return;
        //1,2,3,4
        pair<ListNode*, ListNode*> node_pair=middle_node(head);
        head = node_pair.first;
        ListNode* middle = node_pair.second;
        reverse_listnode(middle);
        head = merge_listnode(head,middle);
    }
};