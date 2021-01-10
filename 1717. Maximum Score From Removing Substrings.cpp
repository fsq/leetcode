class Solution {
public:
    int x, y;
    
    int remove(string& s, string p, int x) {
        string t;
        int ans = 0;
        for (auto c : s) {
            t.push_back(c);
            if (t.size()>=2 && t.substr(t.size()-2, 2)==p) {
                t.pop_back();
                t.pop_back();
                ans += x;
            }
        }
        s.swap(t);
        return ans;
    }
    
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        if (x > y)
            return remove(s, "ab", x) + remove(s, "ba", y);
        else
            return remove(s, "ba", y) + remove(s, "ab", x);
    }
};