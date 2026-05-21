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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>q;
        for (auto l : lists) {
            if (l)
                q.push({l->val, l});
        }
        ListNode dummy;
        ListNode* res = &dummy;
        while (!q.empty()) {
            pair<int, ListNode*> p = q.top();
            q.pop();
            res->next = p.second;
            res = p.second;
            if (res->next) {
                q.push({res->next->val, res->next});
            }
        }
        return dummy.next;
    }
};