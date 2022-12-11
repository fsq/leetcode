class Solution {
public:

    bool dfs(vector<int>& a, vector<int>& b, int cap, int i) {
        if (i==a.size())
            return true;
        else {
            for (int j=0; j<b.size(); ++j)
                if (b[j]+a[i]<=cap) {
                    b[j] += a[i];
                    if (dfs(a, b, cap, i+1)) return true;
                    b[j] -= a[i];
                }
            return false;
        }
    }

    int distributeCookies(vector<int>& a, int k) {
        sort(a.rbegin(), a.rend());
        vector<int> b(k);
        int sum = accumulate(a.begin(), a.end(), 0), n = a.size();
        int l = (sum+k-1) / k, r = sum;
        while (l < r) {
            int mid = (l+r) >> 1;
            if (dfs(a, b, mid, 0)) 
                r = mid;
            else
                l = mid + 1;
            fill(b.begin(), b.end(), 0);
        }
        return l;
    }
};