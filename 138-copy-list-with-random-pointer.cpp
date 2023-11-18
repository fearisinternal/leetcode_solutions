/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (map.count(head)) {
            return map[head];
        }
        Node* copyHead = new Node(head->val);
        map[head] = copyHead;
        copyHead->random = copyRandomList(head->random);
        copyHead->next = copyRandomList(head->next);
        return copyHead;
    }
    unordered_map<Node*, Node*>map;
};