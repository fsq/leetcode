class Solution {
public:
    int numberOfRounds(string s, string f) {
        if (s > f)
            return numberOfRounds(s, "24:00") + numberOfRounds("00:00", f);
        int h1 = stoi(s.substr(0, 2)), h2 = stoi(f.substr(0, 2));
        int m1 = stoi(s.substr(3, 2)), m2 = stoi(f.substr(3, 2));
        m1 = (m1 + 14) / 15 * 15;
        m2 = m2 / 15 * 15;
        int x = h1 * 4 + m1 / 15, y = h2 * 4 + m2 / 15;
        return max(0, y - x);
    }
};