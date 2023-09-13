// 148. 排序链表
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

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
    ListNode* merge(ListNode* list1, ListNode* list2){
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        while (list1 && list2){
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }   
        if (list1) temp->next = list1;
        else if(list2) temp->next = list2;   
        return dummy->next; 
    }
    ListNode* sortList(ListNode* head) {
        //如果head为nullptr直接返回
        if (!head) return head;
        //用于返回head节点
        ListNode* dummy = new ListNode(0,head);
        //计算list长度
        ListNode* temp = head;
        int list_length = 0;
        while (temp)
        {
            ++list_length;
            temp = temp->next;
        }
        //sub_length用于每次计算的sublist的长度，初始值为1，依次翻倍
        for (int sub_length = 1; sub_length<list_length; sub_length<<=1){
            //用于访问各个节点
            ListNode* cur = dummy->next;
            //用于指明每次循环已经排好序的最后一个node
            ListNode* pre = dummy;
            while (cur)
            {
                //计算此次循环需要归并排序的第一个链表
                //head用于指向链表，计算完成后，cur指向需要的排序的子链表的最后一个节点
                ListNode* head1 = cur;
                for (int i = 1; i < sub_length && cur && cur->next; i++)
                {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr; // 第一个链表的最后一个节点指向nullptr
                //计算第二个链表
                cur = head2;
                for (int i = 1; i < sub_length && cur &&  cur->next; i++)
                {
                    cur = cur->next;
                }
                //如果两个子链表之后还有链表，则next指向剩余的链表
                ListNode* next = nullptr; 
                //判断两个子链表之后是否还有链表
                if (cur)
                {
                    next = cur->next;
                    cur->next = nullptr;  //第二个子链表的最后一个节点指向nullptr
                }
                //合并前面的两个子链表       
                ListNode* merged = merge(head1,head2);
                pre->next = merged;
                //更新pre的位置
                while (pre->next)
                {
                    pre = pre->next;   
                }
                //如果next指向的链表还有node则继续计算
                cur = next;               
            }
        }
        return dummy->next;
    }
};