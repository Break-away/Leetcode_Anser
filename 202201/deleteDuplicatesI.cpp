/*����һ�����������е�����������������ͷ�ڵ� head ������ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ��
����ͬ�����������еĽ������*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* ans = head;
        while (head) {
            while (head->next && head->next->val == head->val) {
                head->next = head->next->next;
            }
            head = head->next;
        }
        return ans;
    }
};