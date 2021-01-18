class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        unordered_map<int, int> m;
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                ++m[a[i] * a[j]];
        int ans = 0;
        for (auto& pr : m)
            ans += pr.second * (pr.second-1) *  4;
        return ans;
    }
};