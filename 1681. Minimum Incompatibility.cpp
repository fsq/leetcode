class Solution {
public:
    int ans;
    
    void dfs(vector<int>& a, vector<vector<int>>& b, vector<vector<int>>& put, 
             int i, int cap, int diff) {
        if (i==a.size()) {
            ans = diff;
        } else {
            bool use_empty = false;
            for (int j=0; j<b.size(); ++j) {
                auto& s = b[j];
                if (s.size()<cap && !put[j][a[i]]) {
                    if (s.empty() && use_empty) continue;
                    int inc = s.empty() ? 0 : (a[i]-s.back());
                    if (diff+inc > ans) continue;
                    if (s.empty()) use_empty = true;
                    s.push_back(a[i]);
                    put[j][a[i]] = true;
                    dfs(a, b, put, i+1, cap, diff+inc);
                    s.pop_back();
                    put[j][a[i]] = false;
                }
            }
        }
    }
    
    int minimumIncompatibility(vector<int>& a, int k) {
        if (a.size() == k) return 0;
        sort(a.begin(), a.end());
        ans = (a.back() - a.front()) * k;
        for (int i=0; i+k<a.size(); ++i)
            if (a[i]==a[i+k]) return -1;
        vector<vector<int>> b(k), put(k, vector<int>(a.size()+1));
        dfs(a, b, put, 0, a.size()/k, 0);
        return ans;
    }
};