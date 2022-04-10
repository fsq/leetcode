class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> cd;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '|')
                cd.push_back(i);
        
        vector<int> ans;
        for (auto& q : queries) {
            int li = lower_bound(cd.begin(), cd.end(), q[0]) - cd.begin();
            int ri = upper_bound(cd.begin(), cd.end(), q[1]) - cd.begin();
            if (li >= ri)
                ans.push_back(0);
            else {
                int le = cd[li];
                int re = cd[ri-1];
                ans.push_back(le >= re ? 0 : re-le+1-(ri-li));
            }
        }
        return ans;
    }
};