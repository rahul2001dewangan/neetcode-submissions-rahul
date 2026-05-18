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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL || head == NULL)
            return NULL;
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            temp = temp->next;
            cnt++;
        }
        temp = head;
        for (int i = 1; i < cnt - n; i++) {
            temp = temp->next;
        }
        if (cnt - n == 0)
            return temp->next;
        temp->next = temp->next->next;
        return head;
    }
};