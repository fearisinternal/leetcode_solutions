class Solution {
public:
    bool isValid(string s) {
        stack<char>stack_s;
        for (auto& lit : s)
        {
            if (stack_s.empty() || lit == '{' || lit == '(' || lit == '[')
            {
                stack_s.push(lit);
                continue;
            }   
            while (!stack_s.empty()) {
                char lit_pr = stack_s.top();
                if (lit == ')')
                {
                    if (lit_pr != '(')
                    {
                        return false;
                    }
                    else
                    {                        
                        stack_s.pop();
                        break;
                    }
                }
                if (lit == '}')
                {
                    if (lit_pr != '{')
                    {
                        return false;
                    }
                    else
                    {                        
                        stack_s.pop();
                        break;
                    }
                }
                if (lit == ']')
                {
                    if (lit_pr != '[')
                    {
                        return false;
                    }
                    else
                    {                        
                        stack_s.pop();
                        break;
                    }
                }
            }
        }
    return stack_s.empty();
    }
};