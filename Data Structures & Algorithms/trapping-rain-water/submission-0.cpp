class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int w=0, i = 0, j = height.size() - 1;
        int lm = height[i], rm = height[j];
        while (i < j) {
            if (lm < rm) {
                i++;
                lm = max(height[i], lm);
                w += lm - height[i];
            } else {
                j--;
                rm = max(height[j], rm);
                w += rm - height[j];
            }
        }
        return w;
    }
};