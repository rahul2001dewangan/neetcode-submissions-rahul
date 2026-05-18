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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        ListNode* f = head;
        ListNode* s = prev;
        while (s) {
            ListNode* t1 = f->next;
            ListNode* t2 = s->next;
            f->next = s;
            s->next = t1;
            f = t1;
            s = t2;
        }
    }
};