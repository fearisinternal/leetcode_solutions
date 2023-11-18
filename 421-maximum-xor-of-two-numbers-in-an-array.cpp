class Solution {
public:
class TrieNode {
public:
    TrieNode *child[2];    
    TrieNode() {
        this->child[0] = NULL;
        this->child[1] = NULL;
    }
};

void insert(const int& x, TrieNode* rootNode) {
    TrieNode* trie = rootNode;
    bitset<32>bits(x);        
    for(int i = 31; i >= 0; i--){
        if(!trie->child[bits[i]]) {
            trie->child[bits[i]] = new TrieNode();
        }
        trie = trie->child[bits[i]];
    }    
}

int maxXOR(const int& x, TrieNode* rootNode) {
    TrieNode* trie = rootNode;
    bitset<32> bits(x);        
    long long ans = 0; 
    for(int i = 31; i >= 0; i--) {
        if (trie->child[!bits[i]]) {
            ans+= (1<<i);
            trie = trie->child[!bits[i]];
        }
        else {
            trie = trie->child[bits[i]];
        }
    }
    return ans;
}

    int findMaximumXOR(vector<int>& nums) {
    TrieNode* rootNode = new TrieNode();
    for (auto x : nums) {
        insert(x, rootNode);
    }    
    int ans = 0;
    for (auto x : nums) {
        ans = max(ans, maxXOR(x, rootNode));
    }
    return ans;
    }
};