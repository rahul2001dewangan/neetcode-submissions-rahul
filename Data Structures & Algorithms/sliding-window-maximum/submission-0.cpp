class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), r = 0;
        vector<int> ans;
        ans.reserve(n-k+1);
        deque<int> q;
        for (; r < n; r++) {
            if (!q.empty() && q.front() <= r - k)
                q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[r])
                q.pop_back();
            q.push_back(r);
            if (r + 1 >= k)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};