class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int l = 1;
        long long ans = 1;
        for (int i=1; i<a.size(); ++i) {
            if (a[i]+1 == a[i-1]) ++l; else l = 1;
            ans += l;
        }
        return ans;
    }
};