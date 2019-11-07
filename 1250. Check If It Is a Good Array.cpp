class Solution {
public:
    bool isGoodArray(vector<int>& a) {
        int g = a[0];
        for (auto x : a)
            g = gcd(x, g);
        return g==1;
    }
};