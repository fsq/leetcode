class Solution {
public:
    int getLucky(string s, int k) {
        string x;
        int t = 0;
        for (auto c : s) x += to_string(c - 'a' + 1);
        while (k-- >= 1) {
            t = 0;
            for (auto c : x)
                t += c - '0';
            x = to_string(t);
        }
        return t;
    }
};