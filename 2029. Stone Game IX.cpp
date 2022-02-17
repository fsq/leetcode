class Solution {
public:
    bool stoneGameIX(vector<int>& a) {
        vector<int> c(3);
        for (auto x : a) ++c[x % 3];
        bool flip = c[0] & 1;
        if (c[1] == 0) {
            return c[2]<3 ? false : flip;
        } else if (c[2] == 0) {
            return c[1]<3 ? false : flip;
        } 
        return abs(c[1]-c[2])>2 ? true : !flip;    
    }
};