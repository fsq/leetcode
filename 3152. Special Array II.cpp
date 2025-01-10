class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& queries) {
        vector<int> f(a.size());
        f[0] = 1;
        for (int i=1; i<a.size(); ++i) {
            bool valid = (a[i] ^ a[i-1]) & 1;
            f[i] = valid ? f[i-1] + 1 : 1;
        }
        vector<bool> ans;
        for (auto& q : queries)
            ans.push_back(f[q[1]] >= q[1]-q[0]+1);
        return ans;
    }
};