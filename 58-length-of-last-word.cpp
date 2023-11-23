class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenght = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && lenght == 0)
            {
                continue;
            }
            else if (s[i] != ' ')
            {
                lenght++;
            }
            else
            {
                break;
            }
        }
        return lenght;
    }
};