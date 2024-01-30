class Solution {
public:
    int trap(vector<int>& a) {
        vector<pair<int,int>> q;
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            if (q.size()) {
                int h = q[0].second <= a[i] ? q[0].second : a[i];
                while (q.size() && a[i]>q.back().second) {
                    int w = q.size()==1 ? 0 : q.back().first-q[q.size()-2].first;
                    ans += (h-q.back().second) * w;
                    q.pop_back();
                }
            }
            q.push_back({i, a[i]});
        }
        return ans;
    }
};