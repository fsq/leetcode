class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]<b[0] || a[0]==b[0] && a[1]>b[1];
        });
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int lasty = INT_MAX;
            for (int j=i-1; j>=0; --j) {
                if (a[j][1]<lasty && a[j][1] >= a[i][1]) {
                    ++ans;
                    lasty = a[j][1];
                }
            }
        }
        return ans;
    }
};