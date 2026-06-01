class Solution {
public:
    void getAllCombinations(vector<int>& candidates, vector<int>& combination,
                            vector<vector<int>>& ans, int target, int i) {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        if (i == candidates.size() || target < 0)
            return;
        combination.push_back(candidates[i]);
        getAllCombinations(candidates, combination, ans, target - candidates[i], i);
        combination.pop_back();
        getAllCombinations(candidates, combination, ans, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;
        getAllCombinations(candidates, combination, ans, target, 0);
        return ans;
    }
};