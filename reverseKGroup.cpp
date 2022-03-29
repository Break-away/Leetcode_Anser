using namespace std;
#include <vector>;
#include <algorithm>;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* temp = ans, * len = temp;
        ListNode* cur = temp->next;
        int i = 0;
        while (i < k)
        {
            if (len->next != nullptr)
            {
                i++;
                len = len->next;
            }
            else
            {
                break;
            }
        }
        ListNode* nextlen = reverseKGroup(len, k);
        if (i == k - 1)
        {
            for (int j = 0; j < k; j++)
            {
                ListNode* node1 = temp->next;
                ListNode* node2 = cur;
                ListNode* node3 = cur->next;
                node2->next = node2->next->next;
                node3->next = node1;
                temp->next = node3;
            }
            cur->next = nextlen;
        }
        return ans->next;
    }
};