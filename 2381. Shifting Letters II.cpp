class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> a(n+1);
        for (auto& b : shifts) {
            a[b[0]] += b[2]==1 ? 1 : -1;
            a[b[1]+1] += b[2]==1 ? -1 : 1;
        }
        string t;
        int c = 0;
        for (int i=0; i<n; ++i) {
            c += a[i];
            t.push_back('a' + ((s[i]-'a'+c)%26 + 26)% 26);
        }
        return t;
    }
};