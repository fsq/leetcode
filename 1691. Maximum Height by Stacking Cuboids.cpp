class Solution {
public:
    
    bool greater(vector<int>& a, vector<int>& b) {
        return a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2];
    }
    
    int maxHeight(vector<vector<int>>& a) {
        for (auto& b : a) sort(b.begin(), b.end());
        sort(a.begin(), a.end(), std::greater<vector<int>>());
        int n = a.size() , ans = 0;

        vector<int> f(n);
        for (int i=0; i<n; ++i) {
            f[i] = a[i][2];
            for (int j=0; j<i; ++j)
                if (greater(a[j], a[i]))
                    f[i] = max(f[i], f[j]+a[i][2]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
