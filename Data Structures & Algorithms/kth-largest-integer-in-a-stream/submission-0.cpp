class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minh;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i : nums) {
            minh.push(i);
            if (minh.size() > k)
                minh.pop();
        }
    }

    int add(int val) {
        minh.push(val);
        if (minh.size() > k)
            minh.pop();
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */