class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i = 0, j = 1, m = 0;
        while (i < j && i < n && j < n) {
            if (prices[j] < prices[i]) {
                i = j;
            }
            m = max(prices[j] - prices[i], m);
            j++;
        }
        return m;
    }
};