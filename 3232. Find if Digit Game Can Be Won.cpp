class Solution {
public:
    bool canAliceWin(vector<int>& a) {
        int x=0, y=0;
        for (auto c : a)
            if (c < 10) {
                x += c;
            } else {
                y += c;
            }
        return x != y;
    }
};