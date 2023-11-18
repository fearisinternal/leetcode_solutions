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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode root(0);
        root.next = head;
        ListNode* leftNode = &root;
        for (int i=0; i<left-1; i++) {
            leftNode = leftNode->next;
        }
        ListNode* rightNode = leftNode->next;
        for (int i=left; i<right; i++) {
            ListNode* temp = rightNode->next;
            rightNode->next = temp->next;
            temp->next = leftNode->next;
            leftNode->next = temp;
        }
    return root.next;
    }
};