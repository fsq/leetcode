class Solution {
public:
    vector<int> numOfBurgers(int a, int b) {
        int x = a - 2*b;
        if (x < 0 || (x&1)) return {};
        int y = b - x/2;
        if (y < 0) return {};
        return {x/2, y};
    }
};