class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& a) {
        int n = a.size();
        unordered_map<string,int> rk;
        int id = 0;
        vector<bitset<50000>> f(n);
        for (int i=0; i<n; ++i) {
            for (auto& s : a[i]) {
                if (!rk.count(s)) rk[s] = id++;
                f[i].set(rk[s]);
            }
        }
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            bool ok = true;
            for (int j=0; j<n; ++j)
                if (a[i].size()<a[j].size() && (f[i]&f[j])==f[i]) {
                    ok = false;
                    break;
                }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};