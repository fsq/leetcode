class Solution {
public:
    vector<bool> canEat(vector<int>& a, vector<vector<int>>& queries) {
        vector<long long> s = {a[0]};
        for (int i=1; i<a.size(); ++i)
            s.push_back(s.back() + a[i]);
        vector<bool> ans;
        for (auto& q : queries) {
            long long max_eat = (long long)(q[1]+1) * q[2];
            long long pre = q[0]==0 ? 0 : s[q[0]-1];
            ans.push_back(max_eat > pre && q[1]+1 <= s[q[0]]);
        }
        return ans;
    }
};