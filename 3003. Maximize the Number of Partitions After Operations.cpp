class Solution {
public:

    int n, k;
    vector<vector<int>> ccnt;

    int dist(int l, int r, int change, int x, int y) {
        int ans = 0;
        for (int i=0; i<26; ++i) {
            int cc = ccnt[r+1][i] - ccnt[l][i];
            if (change>=l && change<=r) {
                if (i==x) 
                    --cc;
                else if (i==y) 
                    ++cc;
            }
            if (cc>0) ++ans;
        }
        return ans;
    }

    int FindR(int le, int change, int x, int y) {
        int l=le, r=n-1;
        while (l < r) {
            int mid = (l+r+1) >> 1;
            if (dist(le, mid, change, x, y) > k) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }

    int maxPartitionsAfterOperations(string s, int _k) {
        n = s.size();
        k = _k;
        if (k==26) return 1;
        {
            vector<int> pre(26);
            ccnt.push_back(pre);
            for (int i=0; i<n; ++i) {
                ++pre[s[i]-'a'];
                ccnt.push_back(pre);
            }
        }
        vector<int> pstart(n), pi(n), suf(n+1);
        for (int l=0, r=0, pid=0; l<n; l=r) {
            vector<int> cnt(26);
            int d = 0;
            while (r<n) {
                pstart[r] = l;
                if (++cnt[s[r]-'a'] == 1)
                    ++d;
                if (d <= k) ++r; else break;
            }
            pi[l] = pid++;
        }
        vector<int> cnt(26);
        for (int d=0,l=n-1,r=n-1; l>=0; --l) {
            if (++cnt[s[l]-'a'] == 1) ++d;
            while (d>k) {
                if (--cnt[s[r]-'a'] == 0) --d;
                --r;
            }
            suf[l] = suf[r+1] + 1;
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            int l = pstart[i];
            int head = pi[l];
            int c = 1;
            for (int c=0; c<26; ++c) {
                int r = FindR(l, i, s[i]-'a', c);
                int cur = 0;
                if (r < i) {
                    r = FindR(r+1, i, s[i]-'a', c);
                    cur = head + 2 + suf[r+1];
                } else {
                    cur = head + 1 + suf[r+1];
                }
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};