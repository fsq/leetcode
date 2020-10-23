class Solution {
public:
    
    int rotate(int x, int a) {
        int ori=x, min = x, ans = 0, i = 0;
        do {
            ++i;
            x = (x + a) % 10;
            if (x < min) {
                min = x;
                ans = i;
            }
        } while (x != ori);
        return ans;
    }
    
    string findLexSmallestString(string s, int a, int b) {
        int start = 0;
        string ans = s;
        do {
            string t = s.substr(start) + s.substr(0, start);
            if (b & 1) {
                int p = rotate(t[0]-'0', a), q = rotate(t[1]-'0', a);
                for (int j=0; j<s.size(); j+=2) {
                    char& c = t[j%s.size()];
                    c = (c-'0' + p*a) % 10 + '0';
                    
                    char& d = t[(j+1)%s.size()];
                    d = (d-'0' + q*a) % 10 + '0';
                }
            } else {
                int p = rotate(t[1]-'0', a);
                for (int j=1; j<s.size(); j+=2) {
                    char& c = t[j%s.size()];
                    c = (c-'0' + p*a) % 10 + '0';
                }
            }
            ans = min(ans, t);
            start = (start - b + s.size()) % s.size();
        } while (start != 0);
        return ans;
    }
};