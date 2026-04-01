class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0, i = 0, j = 1, n = prices.size();
        while (i < j && i < n && j < n) {
            if (prices[j] < prices[i]) {
                i = j;
            }
            mp = max(mp, prices[j] - prices[i]);
            j++;
        }
        return mp;
    }
};