class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), marea = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int x = st.top();
                st.pop();
                int p = st.empty() ? -1 : st.top();
                marea = max(marea, heights[x] * (i - p - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int x = st.top();
            st.pop();
            int p = st.empty() ? -1 : st.top();
            marea = max(marea, heights[x] * (n - p - 1));
        }
        return marea;
    }
};