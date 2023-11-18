class Solution {
public:
    string convertToBase7(int num) {
        bool negative = false;
        string num7 = "";
        if (num<0){
            num*=-1;
            negative = true;
        }
        while (num!=0){
            num7=std::to_string(num%7)+num7;
            num/=7;
        }
        if (negative){
            num7 = "-"+num7;
        }
        if (num7.empty()){
            return "0";
        }
        return num7;
    }
};