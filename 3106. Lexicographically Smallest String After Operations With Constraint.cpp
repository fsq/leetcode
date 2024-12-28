class Solution {
public:

    int dist(char a, char b) {
        return min(abs(a-b), 26-abs(a-b));
    }

    string getSmallestString(string s, int k) {
        for (int c=0,i=0; c<k && i<s.size(); ++i) {
            for (auto x='a'; x<='z'; ++x) {
                auto d = dist(x, s[i]);
                if (c+d <= k) {
                    s[i] = x;
                    c += d;
                    break;
                }
            }
        }
        return s;
    }
};