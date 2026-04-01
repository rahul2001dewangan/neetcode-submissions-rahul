class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        for (int i = 0; i < position.size(); i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.rbegin(), car.rend());
        double pt = (double)(target - car[0].first) / car[0].second;
        int fleets = 1;
        for (int i = 1; i < position.size(); i++) {
            double t = (double)(target - car[i].first) / car[i].second;
            if (t > pt) {
                fleets++;
                pt = t;
            }
        }
        return fleets;
    }
};