class Solution {
public:
    string largestOddNumber(string num) {
      int i = num.size();
      while (i > 0)
      {
          if ((num[i - 1] - '0') % 2 != 0)
          {
              break;
          }
          i--;
      }
      return num.substr(0, i);
    }
};