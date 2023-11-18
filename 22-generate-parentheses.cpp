class Solution {
public:

vector<string> ansSequences;

void gen(int n, int round_open, int round_close, string ans) { //square_open, square_close
    if (round_open+round_close == 2*n) {
        ansSequences.push_back(ans);
        return;
    }
    if (round_open < n) gen(n, round_open+1, round_close, ans+'(');
    if (round_open > round_close) gen(n, round_open, round_close+1, ans + ')');
}
    vector<string> generateParenthesis(int n) {
    gen(n, 0, 0, "");
    return ansSequences;
    }
};