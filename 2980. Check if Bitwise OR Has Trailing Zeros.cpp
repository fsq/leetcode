class Solution {
public:
    bool hasTrailingZeros(vector<int>& a) {
        int cnt = 0;
        for (auto x : a) 
            if ((x & 1) == 0) {
                ++cnt;
                if (cnt > 1) return true;
            }
        return false;
    }
};