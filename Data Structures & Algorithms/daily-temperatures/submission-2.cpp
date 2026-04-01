class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> st;
        st.reserve(n);
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.back()] <= temp[i]) {
                st.pop_back();
            }
            if (!st.empty())
                ans[i] = st.back() - i;
            st.push_back(i);
        }
        return ans;
    }
};