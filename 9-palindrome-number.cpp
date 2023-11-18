class Solution {
public:
    bool isPalindrome(int x) {
        int64_t iterx = x;
        int64_t y = 0;
        while (iterx > 0) {
            y=y*10+(iterx%10);
            iterx/=10;
        }
        return x == y;
    }
};