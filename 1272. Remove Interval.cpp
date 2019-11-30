class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intv, vector<int>& rm) {
        vector<vector<int>> ans;
        for (auto& pr : intv)
            if (pr[1] <= rm[0] || pr[0] >= rm[1])
                ans.push_back(move(pr));
            else{
                if (pr[0] < rm[0]) ans.push_back({pr[0], rm[0]});
                if (pr[1] > rm[1]) ans.push_back({rm[1], pr[1]});
            }
        return ans;
                
    }
};