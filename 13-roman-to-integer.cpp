class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> roman{{'M',1000},
                                  {'D',500},
                                  {'C',100},
                                  {'L',50},
                                  {'X',10},
                                  {'V',5},
                                  {'I',1}};
        vector<int> Ints;
        for (auto str : s){
            Ints.push_back(roman.find(str)->second);
        }
        int ans = 0;
        for (auto i = 0; i<Ints.size(); i++)
        {
            if (i+1<Ints.size() && Ints[i]<Ints[i+1])
            {
                ans+=Ints[i+1]-Ints[i];
                i++;
                continue;
            }
            ans+=Ints[i];
        }
        return ans;
    }

};  