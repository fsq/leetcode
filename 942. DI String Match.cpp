class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> a(n+1);
        iota(a.begin(), a.end(), 0);
        for (int j, i=0; i<n; i=j+1) {
            for (j=i; j<n && s[j]=='D'; ++j);
            reverse(a.begin()+i, a.begin()+j+1);
        }
        return a;
    }
};