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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(-1);
        ListNode* res = &dummy;
        while (a && b) {
            if (a->val <= b->val) {
                res->next = a;
                a = a->next;
            } else {
                res->next = b;
                b = b->next;
            }
            res = res->next;
        }
        res->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
        }
        return lists[lists.size() - 1];
    }
};