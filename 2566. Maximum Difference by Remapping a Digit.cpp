class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char mx = ' ';
        for (auto c : s)
            if (c != '9') {
                mx = c;
                break;
            }
        string mxs = s;
        if (mx != ' ') {
            for (auto& c : mxs)
                if (c == mx)
                    c = '9';
        }
        char mn = s[0];
        string mns = s;
        for (auto& c : mns)
            if (c == mn) {
                c = '0';
            }
        return stoi(mxs) - stoi(mns);
    }
};