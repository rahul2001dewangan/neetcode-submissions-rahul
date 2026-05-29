class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mh(stones.begin(), stones.end());
        while (mh.size() > 1) {
            int y = mh.top();
            mh.pop();
            int x = mh.top();
            mh.pop();
            if (x != y) {
                mh.push(y - x);
            }
        }
        return mh.empty() ? 0 : mh.top();
    }
};