class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0){
            return 0;
        }
        int i=0, j=1;
        int maxlen = 1;
        char ind;
        map<char, int>subm;
        subm.insert({s[0],0});
        for (; j<s.length(); j++){
            if (s[i] == s[j] || subm.find(s[j])!=subm.end()) {
                auto dubl = subm.find(s[j]);
                if (dubl->second < i){
                    dubl->second = j;
                    continue;
                }
                if (j-i > maxlen){
                    maxlen = j-i;
                }
                i=dubl->second+1; 
                dubl->second = j;                
            }
            else {
            subm.insert({s[j],j});
            }
        }
        if (j-i > maxlen){
           maxlen = j-i;
        }
        return maxlen;
    }
};