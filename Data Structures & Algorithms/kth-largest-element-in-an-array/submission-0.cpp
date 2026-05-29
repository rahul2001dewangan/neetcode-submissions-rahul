class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int i : nums) {
            if (minh.size() < k)
                minh.push(i);
            else if (minh.top() < i) {
                minh.pop();
                minh.push(i);
            }
        }
        return minh.top();
    }
};