// 147. 对链表进行插入排序
// 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。
// 插入排序 算法的步骤:
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
// 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，
// 从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。
// 对链表进行插入排序。

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        //用于将node插入到head之前的位置，以及指向head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        //用于存放排好序的node中的最后一个，也是val最大的一个
        ListNode* last = head;
        //用于存放当前排序的节点，第一次指向第二个节点
        ListNode* cur = head->next;
        while (cur){
            //如果cur的val大于last的val，则cur的顺序在last之后
            //直接后移last，以及查找下一个节点cur
            if (cur->val >= last->val ){
                cur = cur->next;
                last = last ->next;
            }
            else{
                //pre存放cur节点该存放位置的前一个节点
                //则cur的val大于pre，小于或者等于pre->next
                ListNode* pre = dummy;
                //判断cur的val和pre的val值
                while (cur->val > pre->next->val){
                    pre = pre->next;
                }
                //将cur插入到正确的位置
                last->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = last->next;
        }
        return dummy->next;
    }
};