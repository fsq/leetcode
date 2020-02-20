class Solution {
public:
    double champagneTower(int poured, int x, int y) {
        vector<double> now(x+1), nxt(x+1);
        now[0] = poured;
        for (int i=0; i<x; ++i) {
            fill(nxt.begin(), nxt.end(), 0);
            for (int j=0; j<=i; ++j) 
                if (now[j] > 1) {
                    nxt[j] += (now[j]-1) / 2;
                    nxt[j+1] += (now[j]-1) / 2;
                }
            nxt.swap(now);
        }
        return min<double>(1, now[y]);
    }
};