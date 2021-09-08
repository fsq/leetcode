class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        long long me=0, mo=0, ans=0;
        for (auto x : a) {
            me = max<long long>(me, max<long long>(x, mo+x));
            mo = max<long long>(mo, me-x);
            ans = max(ans, max(me, mo));
        }
        return ans;
    }
};