class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k, m = *max_element(piles.begin(), piles.end());
        int l = 1, r = m, mint = m;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long t = 0;
            for (int i = 0; i < piles.size(); i++) {
                t += (piles[i] + mid - 1) / mid;
            }
            if (t > h)
                l = mid + 1;
            else if (t <= h) {
                mint = mid;
                r = mid - 1;
            }
        }
        return mint;
    }
};