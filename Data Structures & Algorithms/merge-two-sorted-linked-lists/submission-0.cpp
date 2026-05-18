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
    ListNode* mergeTwoLists(ListNode* t1, ListNode* t2) {
        ListNode* t3 = new ListNode(-1);
        ListNode* ans = t3;
        while (t1 && t2) {
            if (t1->val <= t2->val) {
                t3->next = t1;
                t3 = t3->next;
                t1 = t1->next;
            } else {
                t3->next = t2;
                t3 = t3->next;
                t2 = t2->next;
            }
        }
        while (t1) {
            t3->next = t1;
            t3 = t3->next;
            t1 = t1->next;
        }
        while (t2) {
            t3->next = t2;
            t3 = t3->next;
            t2 = t2->next;
        }
        return ans->next;
    }
};
