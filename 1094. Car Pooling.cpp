class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> s(1002);
        for (auto& t : trips) {
            s[t[1]] += t[0];
            s[t[2]] -= t[0];
        }
        int now = 0;
        for (int i=0; i<=1000; ++i) {
            now += s[i];
            if (now > capacity) return false;
        }
        return true;
    }
};