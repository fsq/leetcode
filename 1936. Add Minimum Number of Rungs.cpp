class Solution {
public:
    int addRungs(vector<int>& a, int dist) {
        a.insert(a.begin(), 0);
        int ans = 0;
        for (int i=1; i<a.size(); ++i)
            ans += (a[i] - a[i-1] - 1) / dist;
        return ans;
    }
};