class Solution {
public:
    int splitNum(int num) {
        auto s = to_string(num);
        sort(s.begin(), s.end());
        string x, y;
        for (int i=0; i<s.size(); ++i)
            if (i & 1) {
                y.push_back(s[i]);
            } else {
                x.push_back(s[i]);
            }
        return stoi(x) + stoi(y);
    }
};