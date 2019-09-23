class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        int dis=INT_MAX;
        vector<vector<int>> ans;
        for (int i=0; i+1<a.size(); ++i) {
            int d = a[i+1] - a[i];
            if (d < dis) {
                dis = d;
                ans = vector<vector<int>>{{a[i], a[i+1]}};
            } else if (d == dis) 
                ans.push_back({a[i], a[i+1]});
        }
        return ans;
    }
};