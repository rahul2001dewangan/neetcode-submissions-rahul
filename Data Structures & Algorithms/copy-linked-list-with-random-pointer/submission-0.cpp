/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            if (!temp->random)
                temp->next->random = NULL;
            else
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node dummy(-1);
        Node* res = &dummy;
        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            res->next = copy;
            res = res->next;
            temp = temp->next;
        }
        return dummy.next;
    }
};