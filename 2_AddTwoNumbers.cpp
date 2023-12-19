class Solution {
public:
    // It will return a new Node with the given data
    ListNode* createNode(int data) {
        return new ListNode(data);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL; // Making the head of the answer list
        ListNode *temp; // creating the tempory pointer
        int rem = 0; // It will store the remainder of the addition for each iteration

        // Till both the list are not empty
        while (l1 != NULL && l2 != NULL) {
            int sum = l1 -> val + l2 -> val + rem; // calculating the sum by adding the corresponding element of the LL
            rem = sum / 10;
            // If the list is empty then update the head of the answer list
            if (head == NULL) {
                head = createNode(sum % 10);
                temp = head;
            }
            // If not null then add the new Node to the linked list
            else {
                temp -> next = createNode(sum % 10);
                temp = temp -> next;
            }
            // Move the pointer of the linked list forward
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        // Till list1 not fully traversed
        while (l1 != NULL) {
            int sum = l1 -> val + rem;
            rem = sum / 10;
            if (head == NULL) {
                head = createNode(sum % 10);
                temp = head;
            }
            else {
                temp -> next = createNode(sum % 10);
                temp = temp -> next;
            }
            l1 = l1 -> next;
        }
        // Till list2 not fully traversed
        while (l2 != NULL) {
            int sum = l2 -> val + rem;
            rem = sum / 10;
            if (head == NULL) {
                head = createNode(sum % 10);
                temp = head;
            }
            else {
                temp -> next = createNode(sum % 10);
                temp = temp -> next;
            }
            l2 = l2 -> next;
        }
        // If the value of the remender is not zero then we add an extra node
        if (rem != 0) {
            temp -> next = createNode(rem);
        }
        return head; // Return the new Linked list
    }
};
