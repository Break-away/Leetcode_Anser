/*给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    //反转局部链表
    ListNode* reverselist(ListNode* head) {
        ListNode* cur = new ListNode(-1);
        cur->next = nullptr;
        while (head) {
            ListNode* temp = head;
            head = head->next;
            temp->next = cur->next;
            cur->next = temp;
        }
        return cur->next;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* cur = new ListNode(-1), * mid, * temp, * begin, * end;
        cur->next = head;
        temp = cur;
        for (int i = 1; i < left; ++i) {
            temp = temp->next;
        }
        begin = temp;
        //链表开始反转位置
        mid = temp->next;
        //查找链表反转结束位置
        for (int i = left; i <= right; ++i) {
            temp = temp->next;
        }
        end = temp->next;
        temp->next = nullptr;
        mid = reverselist(mid);
        //链接链表开始反转位置
        begin->next = mid;
        while (mid->next) {
            mid = mid->next;
        }
        //链接链表反转结束位置
        mid->next = end;
        return cur->next;
    }
};