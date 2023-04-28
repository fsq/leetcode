class Solution {
public:
    unordered_map<int, int> m;

    int pow(int x) {
        if (x==1) return 2;
        if (x==0) return 1;
        if (m.count(x)) return m[x];
        long long s = pow(x/2);
        return m[x] = (s * s * ((x&1) ? 2 : 1)) % 1000000007;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> a;
        for (int i=0; i<32; ++i)
            if ((n>>i) & 1)
                a.push_back(i);
        for (int i=1; i<a.size(); ++i) a[i] += a[i-1];
        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(pow(a[q[1]]-(q[0]==0 ? 0 : a[q[0]-1])));
        } 
        return ans;
    }
};