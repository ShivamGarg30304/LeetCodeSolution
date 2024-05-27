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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* temp = head;
        ListNode* temp1 = head -> next;
        while (temp1 != NULL) {
            while (temp1 != NULL and temp1 -> val == temp -> val) {
                temp1 = temp1 -> next;
            }
            temp -> next = temp1;
            temp = temp1;
            if (temp1 != NULL) temp1 = temp1 -> next;
        }
        return head;
    }
};