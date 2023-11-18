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
        ListNode* newHead = new ListNode(-1000, head);
        ListNode* prev = newHead;
        ListNode* cur = head;
        while (cur != NULL) {
            if (cur->next != NULL && cur->val == cur->next->val) {
                while (cur->next != NULL && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                prev->next = cur->next;
            }
            else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return newHead->next;
    }
};