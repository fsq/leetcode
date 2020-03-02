class Solution {
public:
    string rankTeams(vector<string>& v) {
        int n = v[0].size();
        vector<vector<int>> m(26, vector<int>(n));
        for (auto& r : v)
            for (int i=0; i<n; ++i) 
                ++m[r[i]-'A'][i];
            
        vector<pair<char, vector<int>>> a;
        for (int i=0; i<26; ++i) a.push_back({'A'+i, move(m[i])});
        sort(a.begin(), a.end(), [](pair<char,vector<int>>& a, pair<char,vector<int>>& b) {
            return a.second>b.second || a.second==b.second &&  a.first<b.first;
        });
        string ans;
        for (int i=0; i<n; ++i) ans.push_back(a[i].first);
        return ans;
    }
};