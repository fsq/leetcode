class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& b, long long success) {
        vector<vector<int>> a;
        for (int i=0; i<sp.size(); ++i) a.push_back({sp[i], i});
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int> ans(a.size());        
        int j = b.size() - 1;
        for (auto& p : a) {
            while (j>=0 && (long long)p[0]*b[j]>=success) {
                --j;
            }
            ans[p[1]] = b.size() - j - 1;
        }
        return ans;
    }
};