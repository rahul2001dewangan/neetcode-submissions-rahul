class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string i : tokens) {
            if (i == "+") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            } else if (i == "-") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            } else if (i == "*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            } else if (i == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            } else
                st.push(stoi(i));
        }
        return st.top();
    }
};