class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> mh;
        for (int i = 0; i < points.size(); i++) {
            int dist2 =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            mh.push({dist2, i});
            if (mh.size() > k)
                mh.pop();
        }
        vector<vector<int>> ans;
        while (!mh.empty()) {
            ans.push_back(points[mh.top().second]);
            mh.pop();
        }
        return ans;
    }
};