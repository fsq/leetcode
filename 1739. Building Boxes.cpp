class Solution {
public:
    int minimumBoxes(int n) {
        int btm = 0, h = 0, s = 0;
        while (s < n) {
            ++h;
            btm += h;
            s += btm;
        }
        if (s==n) return btm;
        --h;
        s -= btm;
        int r = n - s;
        double delta = 1 + 8*r;
        int y = (-1 + sqrt(delta)) / 2;
        if (y*(y+1)/2 < r) ++y;
        return h * (h+1) / 2 + y;
    }
};
// (1+y)*y=2r
// y^2 + y - 2r = 0;