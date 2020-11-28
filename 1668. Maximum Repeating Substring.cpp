class Solution {
public:
    int maxRepeating(string s, string w) {
        int ans = 0;
        string b;
        for (int i=1; w.size()*i<=s.size(); ++i) {
            b += w;
            if (s.find(b) != string::npos) 
                ans = i;
        }
        return ans;
    }
};