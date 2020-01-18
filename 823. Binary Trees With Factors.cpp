class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        unordered_map<int, long long> f;
        sort(a.begin(), a.end());
        for (int i=0; i<a.size(); ++i) {
            int ans = 1;
            for (int j=0; j<i; ++j)
                if (a[i]%a[j]==0 && f.count(a[i]/a[j])) 
                    ans = (ans + f[a[i]/a[j]]*f[a[j]]) % 1000000007;
            f[a[i]] = ans;
        }
        int ans = 0;
        for (auto& pr : f)
            ans = (ans + pr.second) % 1000000007;
        return ans;
    }
};