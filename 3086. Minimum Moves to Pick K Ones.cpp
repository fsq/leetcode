class Solution {
public:
    long long minimumMoves(vector<int>& num, int k, int maxChanges) {
        vector<long long> a;
        for (int i=0; i<num.size(); ++i)
            if (num[i] == 1)
                a.push_back(i);
        if (a.size()==0) return k * 2;
        // how many more 1s needed beyond maxChanges
        int len = max(k-maxChanges, 1);
        int l=0, r=l+len-1;
        long long d = 0;
        for (int i=l; i<=r && i<a.size(); ++i)
            d += abs(a[i] - a[0]);
        long long ans = LLONG_MAX;
        // iterate starting point
        for (int i=0; i<a.size(); ++i) {
            long long stp = 0;
            int x = a[i];
            bool l1 = x>0 && num[x-1]==1 && a[l]>x-1;
            bool r1 = x+1<num.size() && num[x+1]==1 && a[r]<x+1;
            if (maxChanges >= k) {
                stp = 2*(k-1);
                if (stp>1 && x>0 && num[x-1]==1) {
                    --stp;
                }
                if (stp>1 && x+1<num.size() && num[x+1]==1) {
                    --stp;
                }
            } else {
                int c = maxChanges;
                stp = c*2 + d;
                if (c == k-1) {
                    if (c>0 && l1) --c, --stp;
                    if (c>0 && r1) --c, --stp;
                } else if (c == k-2) {
                    if (c>0 && (l1 || r1)) --c, --stp;
                }
                // update l,r to calculate new d
                if (i+1<a.size()) {
                    int x=a[i], xt=a[i+1];
                    d = d + (i+1-l)*(xt-x) - (r-i)*(xt-x);
                    while (r+1<a.size() && a[r+1]-xt<=xt-a[l]) {
                        d = d - (xt-a[l]) + (a[r+1]-xt);
                        ++l;
                        ++r;
                    }
                }
            }
            ans = min(ans, stp);
        }
        return ans;
    }
};