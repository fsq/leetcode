class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = 0;
        for (int s=0,cur=0,i=n-1; i>=0; --i) {
            s += a[i];
            cur += s;
            ans = max(ans, cur);
        }
        return ans;
    }
};