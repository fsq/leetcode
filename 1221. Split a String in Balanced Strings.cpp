class Solution {
public:
    int balancedStringSplit(string s) {
        int x = 0, ans = 0;
        for (auto c : s) {
            if (c=='L')
                ++x;
            else 
                --x;
            if (!x) ++ans;
        }
        return ans;
    }
};