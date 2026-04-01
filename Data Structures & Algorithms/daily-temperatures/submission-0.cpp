class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                int t = st.top();
                if (temp[i] < temp[t]) {
                    ans[i] = t - i;
                    break;
                } else {
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};