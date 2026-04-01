class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        int n =position.size();
        car.reserve(n);
        stack<float> time;
        int fleets = 0;
        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end());
        for (auto c : car) {
            cout << c.first << " " << c.second << endl << endl;
        }
        for (int i = 0; i < n; i++) {
            time.push(float(target - car[i].first) / float(car[i].second));
        }
        while (!time.empty()) {
            float x = time.top();
            time.pop();
            fleets++;
            while (!time.empty() && time.top() <= x)
                time.pop();
        }
        return fleets;
    }
};