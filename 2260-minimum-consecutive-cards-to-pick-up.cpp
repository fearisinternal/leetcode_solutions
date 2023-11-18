class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int>cardd;
        int ans = cards.size()+1;
        for (auto i =0; i<cards.size(); i++){
            if (cardd.find(cards[i])!=cardd.end()){
                ans = min(ans,i-cardd.find(cards[i])->second+1);
                cardd.find(cards[i])->second = i;
            }
            cardd.insert({cards[i], i});
        }
        if (ans>cards.size()){
            ans = -1;
        }
        return ans;
    }
};