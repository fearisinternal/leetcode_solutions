class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        for (auto i = 0; i < number.size(); i++) {
            if (number[i]==digit) {
                if (ans < number.substr(0,i)+number.substr(i+1)) {
                    ans = number.substr(0,i)+number.substr(i+1);
                }       
            }
        }
    return ans;
    }
};