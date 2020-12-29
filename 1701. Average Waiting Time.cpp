class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double t=0, s=0;
        for (auto& a : customers) {
            t = max<double>(a[0], t) + a[1];
            s += t - a[0];
        }
        return s / (double)customers.size();
    }
};