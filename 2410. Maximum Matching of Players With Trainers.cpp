class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 0, i = 0;
        for (auto x : a) {
            while (i<b.size() && b[i]<x) ++i;
            if (i==b.size()) break;
            ++ans;
            ++i;
        }
        return ans;
    }
};