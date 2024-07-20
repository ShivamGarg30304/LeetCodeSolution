class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for (auto num : nums) st.insert(num);
        while (head != NULL && st.find(head -> val) != st.end()) {
            head = head -> next;
        }
        ListNode *prev = head;
        ListNode *temp = head -> next;
        while (temp != NULL) {
            int val = temp -> val;
            if (st.find(val) == st.end()) {
                prev -> next = temp;
                prev = temp;
            }
            temp = temp -> next;
        }
        prev -> next = NULL;
        return head;
    }
};