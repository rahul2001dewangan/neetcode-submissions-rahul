class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); i++) {
            int f = target - nums[i];
            if (s.find(f) == s.end()) {
                s.insert({nums[i], i});
            } else {
                ans.push_back(s.at(f));
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
