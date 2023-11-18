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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* lastpoint = head;
        int numOfPoints = 1;
        while (lastpoint->next != NULL) {
            lastpoint = lastpoint->next;
            numOfPoints++;
        }
        lastpoint->next = head;
        lastpoint = head;
        int newStart = numOfPoints - (k%numOfPoints)-1;
        for (int i = 0; i < newStart; i++) {
            lastpoint = lastpoint->next;
        }
        head = lastpoint->next;
        lastpoint->next = NULL;
        return head;
    }
};