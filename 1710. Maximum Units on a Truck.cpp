class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int s) {
        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1]; 
        });
        int ans = 0, i = 0;
        for (int i=0; i<a.size() && s; ++i) {
            int put = min(a[i][0], s);
            ans += a[i][1] * put;
            s -= put;
        }
        return ans;
    }
};