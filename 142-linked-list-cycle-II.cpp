/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* l = head;
        ListNode* r = head;
        set<ListNode*>cycleNode;
        while (r){
            if (r->next)
                r = r->next->next;
            else
                r=r->next;
            if (cycleNode.find(l)!=cycleNode.end()){
                return l;
            }
            cycleNode.insert(l);
            l = l->next;
        }
        return r;
    }
};