class Solution {
public:

    long long count(vector<int>& a, long long m) {
        unordered_map<int, int> cnt;
        int uni = 0;
        long long ans = 0;
        for (int l=0,r=0; l<a.size(); ++l) {
            while (r<a.size() && (cnt[a[r]]>0 || uni+1<=m)) {
                if (++cnt[a[r]] == 1) ++uni;
                ++r;
            }
            ans += r - l;
            if (--cnt[a[l]] == 0) {
                --uni;
            }
        }
        return ans;
    }

    int medianOfUniquenessArray(vector<int>& a) {
        long long n = a.size();
        auto tot = n * (n+1) / 2;
        auto target = (tot+1) / 2;
        long long l = 1, r = unordered_set<int>(a.begin(), a.end()).size();
        while (l < r) {
            long long m = (l + r) >> 1;
            long long cnt = count(a, m);
            if (cnt < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};