class Solution {
public:
    bool isSubsequence(string s, string t) {
        int indS = 0;
        for (auto ch : t){            
            if (indS>s.size()){
                return true;
            }
            if (s[indS]==ch){
                indS++;
            }
        }
        return indS>=s.size();        
    }
};