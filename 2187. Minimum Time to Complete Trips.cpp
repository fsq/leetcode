class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = (long long)totalTrips*time[0];
        while (l < r) {
            long long m = (l + r) >> 1;
            long long t = 0;
            for (auto x : time) t += m/x;
            if (t < totalTrips) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};