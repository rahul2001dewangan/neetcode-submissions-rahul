class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy = 0, aheadBuy2 = 0, aheadHold = 0;
        for (int i = n - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] + aheadHold, aheadBuy);
            int currHold = max(prices[i] + aheadBuy2, aheadHold);
            aheadBuy2 = aheadBuy;
            aheadBuy = currBuy;
            aheadHold = currHold;
        }
        return aheadBuy;
    }
};