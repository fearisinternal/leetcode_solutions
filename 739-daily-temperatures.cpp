class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> answers(temperatures.size());
        std::stack<int> days;
        for (auto i = 0; i < temperatures.size(); i++)
        {
            while (!days.empty() && temperatures[days.top()] < temperatures[i])
            {
                answers[days.top()] = i-days.top();
                days.pop();
            }
            days.push(i);
        }
        return answers;
    }
};