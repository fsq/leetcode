class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        string ans;
        int r = rows, c = s.size() / rows;
        for (int i=0; i<c; ++i) {
            int x=0, y=i;
            while (x<r && y<c) {
                ans.push_back(s[x*c + y]);
                ++x, ++y;
            }
        }
        while (!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};