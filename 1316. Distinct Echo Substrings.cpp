class Solution {
public:
    const int M = 1e9 + 7;
    
    int distinctEchoSubstrings(string s) {
        unordered_set<int> ans;
        for (int i=0, j; i<s.size(); ++i) {
            j = i + 1;
            long long x = 0, y = 0, p = 1;
            for (int l=0; i-l>=0 && j+l<s.size(); ++l) {
                x = ((x*26) + (s[i-l]-'a'+1)) % M;
                y = (y + (s[j+l]-'a'+1)*p) % M;
                if (x==y && !ans.count(x)) ans.insert(x);
                p = p*26 % M;
            }
        }
        return ans.size();
    }
};