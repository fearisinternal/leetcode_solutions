class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0;
        int profit = 0;
        int p_max = prices[0];
        for (j=1;j<prices.size(); j++){
            if (prices[j]>p_max){
                p_max = prices[j];
            }
            if (prices[j]<prices[i])
            {
                if (p_max-prices[i] > profit){
                    profit = p_max-prices[i];
                }
                i=j; 
                p_max = prices[i];
            }
        }
        if (p_max-prices[i] > profit){
            profit = p_max-prices[i];
        }
        return profit;
    }
};