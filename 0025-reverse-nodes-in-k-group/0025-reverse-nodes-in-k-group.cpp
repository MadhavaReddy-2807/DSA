class Solution {
public:
    ListNode* reverse(ListNode*& head, ListNode*& tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) {
            return head;
        }
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        ListNode* first = head;
        ListNode* second = head;
        ListNode* pend = NULL;
        for (int i = 0; i < count / k; i++) {
            for (int j = 0; j < k - 1; j++) {
                second = second->next;
            }
            ListNode* nestart = second->next;
            ListNode* nstart = reverse(first, second);
            if (pend != NULL) {
                pend->next = nstart;
            } else {
                head = nstart;
            }
            pend = first;
            first->next = nestart;
            first = nestart;
            second = first;
        }
        return head;
    }
};
