class Solution {
public:
    
    pair<int,int> find(const vector<int>& a) {
        int s1=20000, s2=20000;
        for (auto x : a)
            if (x <= s1) 
                s2 = s1, s1 = x;
            else if (x < s2)
                s2 = x;
        return {s1, s2};
    }
    
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> now(m), nxt(m);
        for (int s1,s2,i=0; i<n; ++i) {
            tie(s1, s2) = find(now);
            for (int j=0; j<m; ++j)
                nxt[j] = (now[j]==s1 ? s2: s1) + a[i][j];
            nxt.swap(now);
        }
        return *min_element(now.begin(), now.end());
    }
};