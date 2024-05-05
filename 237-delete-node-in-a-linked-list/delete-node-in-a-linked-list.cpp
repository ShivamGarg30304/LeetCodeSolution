class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * ptr = node -> next;
        node -> val = ptr -> val;
        node -> next = ptr -> next;
    }
};