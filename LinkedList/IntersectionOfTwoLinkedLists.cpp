/*
Problem:
LeetCode 160 - Intersection of Two Linked Lists

Approach:
Pointer Switching

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode *getIntersectionNode(
        ListNode *headA,
        ListNode *headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b) {

            a = (a == nullptr)
                    ? headB
                    : a->next;

            b = (b == nullptr)
                    ? headA
                    : b->next;
        }

        return a;
    }
};
