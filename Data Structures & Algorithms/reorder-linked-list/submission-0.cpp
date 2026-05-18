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
        ListNode* temp = head;
        stack<ListNode*> st;
        int cnt = 0;
        while (temp) {
            st.push(temp);
            cnt++;
            temp = temp->next;
        }
        temp = head;
        while (temp && cnt >= 0 && !st.empty()) {
            if (cnt == 1) {
                temp->next = NULL;
            } else if (cnt == 0) {
                temp->next = NULL;
            } else {
                ListNode* x = st.top();
                st.pop();
                x->next = temp->next;
                temp->next = x;
                temp = x->next;
            }
            cnt -= 2;
        }
    }
};