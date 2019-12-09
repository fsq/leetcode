class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
        vector<pair<int,int>> a;
        for (int i=0; i<n; ++i) a.push_back({gs[i], i});
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i=0,j; i<n; i=j) {
            vector<int> now;
            for (j=i; j<i+a[i].first; ++j) {
                now.push_back(a[j].second);
            }
            ans.push_back(move(now));
        } 
        return ans;
    }
};