/*
Problem:
LeetCode 234 - Palindrome Linked List

Approach:
Find middle, reverse second half,
compare both halves.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    ListNode* reverseList(
        ListNode* head) {

        ListNode* prev = nullptr;

        while(head) {

            ListNode* nextNode =
                head->next;

            head->next = prev;

            prev = head;
            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(
        ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(
            fast &&
            fast->next
        ) {

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second =
            reverseList(slow);

        ListNode* first = head;

        while(second) {

            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
