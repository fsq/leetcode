class Solution {
public:
    int minimumSeconds(vector<int>& a) {
        unordered_map<int, vector<int>> p;
        for (int i=0; i<a.size(); ++i)
            p[a[i]].push_back(i);
        int ans = INT_MAX, n = a.size();
        for (auto& pr : p) {
            auto& a = pr.second;
            int cost = INT_MIN;
            for (int i=0; i<a.size(); ++i) {
                int d = i+1==a.size() ? (a[0]+n-a[i]) : (a[i+1]-a[i]);
                cost = max(cost, d/2);
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};