class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& a, vector<int>& b, int capacity) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = b[0] - 1, j = 0;
        for (auto& av : a) {
            int on = capacity;
            while (j<b.size() && on && b[j]<=av) {
                if (j==0 || b[j]>b[j-1]+1) {
                    ans = b[j] - 1;
                }
                --on;
                ++j;
            }
            if (on>0 && (j==0 || b[j-1]!=av)) {
                ans = av;
            }
        }
        return ans;
    }
};