class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> a(n);
        a[p] = 1;
        unordered_set<int> ban(banned.begin(), banned.end());
        queue<int> q;
        vector<set<int>> st(2);
        for (int i=0; i<n; ++i) 
            if (!ban.count(i) && i!=p)
                st[i & 1].insert(i);
        q.push(p);
        while (q.size()) {
            int x = q.front(); q.pop();
            int o = (x+k-1) & 1;
            int l = x-k+1, r=x+k-1;
            auto it = st[o].lower_bound(l);
            while (it!=st[o].end() && *it<=r) {
                int y = *it, d = (k-(abs(x-y)+1))/2;
                if (min(x,y)>=d && max(x,y)+d<n) {
                    a[y] = a[x] + 1;
                    q.push(y);
                    it = st[o].erase(it);
                } else 
                    ++it;
            }
        }
        for (auto& x : a)
            if (x==0)
                x = -1;
            else
                --x;
        return a;
    }
};