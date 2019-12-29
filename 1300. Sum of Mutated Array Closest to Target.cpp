class Solution {
public:
    int findBestValue(vector<int>& a, int target) {
        int l = 0, r = 100000;
        auto f = [&](int m) {
            int s = 0;
            for (auto x : a) 
                s += x > m ? m : x;
            return s;
        };
        while (l < r) {
            int m = (l+r) >> 1, s = f(m);
            if (s >= target)
                r = m;
            else
                l = m + 1;
        }
        return f(l)-target >= target-f(l-1) ? l-1 : l;
    }
};