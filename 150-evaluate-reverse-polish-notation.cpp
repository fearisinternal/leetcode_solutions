class Solution
{
public:
    int evalRPN(std::vector<string> &tokens)
    {
        std::stack<int> s;
        for (auto &str : tokens)
        {
            if (str.size() == 1 && !isdigit(str[0]))
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (str == "+")
                {
                    s.push(num1 + num2);
                }
                else if (str == "-")
                {
                    s.push(num2 - num1);
                }
                else if (str == "/")
                {
                    s.push(num2 / num1);
                }
                else if (str == "*")
                {
                    s.push(num1 * num2);
                }
            }
            else
            {
                s.push(std::atoi(str.c_str()));
            }
        }
        return s.top();
    }
};