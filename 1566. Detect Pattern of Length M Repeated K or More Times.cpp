class Solution {
public:
    bool containsPattern(vector<int>& a, int m, int k) {
        for (int i=0; i+m*k<=a.size(); ++i) {
            bool ok = true;
            for (int j=0; j<m; ++j) {
                int c = a[i + j];
                for (int r=1; r<k; ++r) 
                    if (c != a[i + r*m + j]) {
                        goto last;
                    }
            }
            if (ok) return true;
            last: continue;
        }
        return false;
    }
};