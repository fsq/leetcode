class Solution {
public:
    string maximumBinaryString(string s) {
        vector<int> c(2);
        for (auto& x : s) {
            if (x=='1' && c[0]==0)
                ++c[1];
            else if (x=='0')
                ++c[0];
            x = '1';
        }
        if (c[1] < s.size())
            s[c[1] + c[0] - 1] = '0';
        return s;
    }
};
