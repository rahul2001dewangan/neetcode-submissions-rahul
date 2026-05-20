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
            temp = t->next;
        }
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node dummy(-1);
        Node* res = &dummy;
        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;
            res->next = copy;
            res = copy;
            temp = temp->next;
        }
        return dummy.next;
    }
};