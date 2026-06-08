/*
Problem:
LeetCode 19 - Remove Nth Node From End of List

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for(int i = 0; i <= n; i++)
            fast = fast->next;

        while(fast) {

            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
