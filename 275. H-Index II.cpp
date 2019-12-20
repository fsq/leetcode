class Solution {
public:
    int hIndex(vector<int>& a) {
        if (a.empty()) return 0;
        int l = 0, r = a.size();
        while (l < r) {
            int m = (l+r+1) >> 1;
            if (a[a.size()-m] >= m)
                l = m;
            else 
                r = m - 1;
        }
        return l;
    }
};