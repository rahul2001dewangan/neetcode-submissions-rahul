class TimeMap {
    unordered_map<string, vector<pair<string, int>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        string ans="";
        if (mp.find(key) != mp.end()) {
            auto& v = mp[key];
            int l = 0, r = v.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (v[m].second <= timestamp) {
                    l = m + 1;
                    ans = v[m].first;
                } else
                    r = m - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */