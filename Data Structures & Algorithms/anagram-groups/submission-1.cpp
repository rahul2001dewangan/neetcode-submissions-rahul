#include<array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>,vector<string>> s;
        for(string a : strs){
            array<int,26> arr{};
            for(char i: a){
                arr[i-'a']++;
            }
            s[arr].push_back(a);
        }
        vector<vector<string>> ans;
        for(auto x : s){
            ans.push_back(x.second);
        }
        return ans;
    }
};
