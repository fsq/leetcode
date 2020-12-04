class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            ans = max(ans, accumulate(a[i].begin(), a[i].end(), 0));
        return ans;
    }
};