class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char,char>alphabetS;
        std::map<char,char>alphabetT;
        for (auto i = 0; i < s.size(); i++)
        {
            auto ti = alphabetS.find(s[i]);
            auto si = alphabetT.find(t[i]);
            if (ti!=alphabetS.end())
            {
              if (ti->second != t[i]){
               return false; 
              }
            }
            else if (si!=alphabetT.end()){                
              if (si->second != s[i]){
               return false; 
              }
            }
            else
            {
                alphabetS.insert({s[i], t[i]});
                alphabetT.insert({t[i], s[i]});
            }
        }
        return true;
    }
};