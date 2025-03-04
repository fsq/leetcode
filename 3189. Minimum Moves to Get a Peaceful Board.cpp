class Solution {
public:
    int minMoves(vector<vector<int>>& a) {
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i=0; i<a.size(); ++i) {
            ans += abs(a[i][0] - i);
            a[i][0] = i;
        }
        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        for (int i=0; i<a.size(); ++i) {
            ans += abs(a[i][1] - i);
        }
        return ans;
    }
};