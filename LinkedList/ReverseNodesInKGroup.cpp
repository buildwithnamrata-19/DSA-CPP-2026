class Solution {
public:

    ListNode* reverseKGroup(
        ListNode* head,
        int k) {

        ListNode* curr = head;

        int count = 0;

        while(curr && count < k) {
            curr = curr->next;
            count++;
        }

        if(count < k)
            return head;

        curr = head;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        count = 0;

        while(curr && count < k) {

            nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;

            count++;
        }

        if(nextNode)
            head->next =
                reverseKGroup(nextNode, k);

        return prev;
    }
};
