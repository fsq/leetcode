class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        map<int, int> m;
        for (auto x : a) ++m[x];
        vector<int> ans;
        for (auto &pr : m) 
            if (pr.second == 0)
                continue;
            else if (pr.first==0) {
                if (pr.second & 1) 
                    return {};
                else 
                    ans.insert(ans.end(), pr.second/2, 0);
            } else if (pr.second <= m[pr.first*2]) {
                ans.insert(ans.end(), pr.second, pr.first);
                m[pr.first*2] -= pr.second;
            } else 
                return {};
        return ans;
    }
};