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
    ListNode* reverse(ListNode* head) {
        ListNode* p = NULL;
        ListNode* curr = head;
        ListNode* after = NULL;
        while (curr) {
            after = curr->next;
            curr->next = p;
            p = curr;
            curr = after;
        }
        return p;
    }

    ListNode* getkNode(ListNode* head, int k) {
        k -= 1;
        while (head && k > 0) {
            k--;
            head = head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* Last = NULL;
        while (temp) {
            ListNode* kNode = getkNode(temp, k);
            if (kNode == NULL) {
                if (Last)
                    Last->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kNode;
            } else {
                Last->next = kNode;
            }
            Last = temp;
            temp = nextNode;
        }
        return head;
    }
};