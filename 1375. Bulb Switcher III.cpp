class Solution {
public:
    int numTimesAllBlue(vector<int>& a) {
        int ans = 0, mx = 0;
        for (int i=0; i<a.size(); ++i) {
            mx = max(mx, a[i]);
            ans += mx == i+1;
        }
        return ans;
    }
};