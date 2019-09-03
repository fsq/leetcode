class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> c(1, vector<int>(26));
        ++c[0][s[0]-'a'];
        for (int i=1; i<n; ++i) {
            c.push_back(c.back());
            ++c.back()[s[i]-'a'];
        }
        vector<bool> ans;
        for (auto& q : queries) {
            vector<int> a(26);
            for (int i=0; i<26; ++i) 
                a[i] = c[q[1]][i] - (q[0]==0 ? 0 : c[q[0]-1][i]);
            int k = q[2], od = 0;
            for (int i=0; i<26; ++i)
                if (a[i] & 1)
                    ++od;
            ans.push_back(k >= od/2);
        }
        return ans;
    }
};
