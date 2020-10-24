class Solution {
public:
    int bestTeamScore(vector<int>& b, vector<int>& a) {
        vector<pair<int,int>> s;
        int n = a.size();
        for (int i=0; i<n; ++i)
            s.push_back({a[i], b[i]});
        sort(s.begin(), s.end());
        vector<int> h(n);   
        for (int i=0; i<n; ++i) {
            h[i] = s[i].second;
            for (int j=0; j<i; ++j)
                if (s[i].second >= s[j].second)
                    h[i] = max(h[i], s[i].second + h[j]);
        }
        
        return *max_element(h.begin(), h.end());
    }
};