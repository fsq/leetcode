class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& qr) {
        vector<int> s(a.size()+1);
        for (int i=0; i<a.size(); ++i)
            s[i+1] = s[i] ^ a[i];
        vector<int> ans;
        for (auto& q : qr)
            ans.push_back(s[q[1]+1] ^ s[q[0]]);
        return ans;
    }
};