class Solution {
public:
    int maxJump(vector<int>& a) {
        int ans = a[1] - a[0];
        for (int i=2; i<a.size(); ++i)
            ans = max(ans, a[i] - a[i-2]);
        return ans;
    }
};