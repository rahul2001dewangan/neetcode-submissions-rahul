class MinStack {
    stack<long> st;
    long minel;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(0);
            minel = val;
        } else {
            st.push(val - minel);
            minel = min((long)val, minel);
        }
    }

    void pop() {
        if (!st.empty()) {
            long x = st.top();
            st.pop();
            if (x < 0)
                minel -= x;
        }
    }

    int top() {
        long x = st.top();
        if (x <= 0)
            return minel;
        else
            return minel + x;
    }

    int getMin() { return minel; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */