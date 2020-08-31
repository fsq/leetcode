class Solution {
public:
    // bool containsPattern(vector<int>& a, int m, int k) {
    //     for (int i=0; i+m*k<=a.size(); ++i) {
    //         bool ok = true;
    //         for (int j=0; j<m; ++j) {
    //             int c = a[i + j];
    //             for (int r=1; r<k; ++r) 
    //                 if (c != a[i + r*m + j]) {
    //                     goto last;
    //                 }
    //         }
    //         if (ok) return true;
    //         last: continue;
    //     }
    //     return false;
    // }
    bool containsPattern(vector<int>& a, int m, int k) {
        int len = 0;
        for (int i=0; i+m<a.size(); ++i) {
            if (a[i] != a[i+m])
                len = 0;
            else if (++len == m*(k-1))
                return true;
        }
        return false;
    }
};