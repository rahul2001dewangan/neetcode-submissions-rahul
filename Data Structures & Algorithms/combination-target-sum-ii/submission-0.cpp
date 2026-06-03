class Solution {
public:
    void getAllCombinations(vector<int>& candidates, int target, int i,
                            vector<int>& comb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            comb.push_back(candidates[j]);
            getAllCombinations(candidates, target - candidates[j], j + 1, comb,
                               ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        getAllCombinations(candidates, target, 0, comb, ans);
        return ans;
    }
};