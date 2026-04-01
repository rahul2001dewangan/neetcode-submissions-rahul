class Solution {
public:
    static bool comp(const pair<int,int>& a, const pair<int,int>& b){
        return a.second>=b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto it:nums){
            if(m.find(it)!=m.end()){
                m[it]++;
            }
            else{
                m[it]=1;
            }
        }
        vector<pair<int,int>> mp(m.begin(),m.end());
        sort(mp.begin(),mp.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(mp[i].first);
        }
        return ans;
    }
};