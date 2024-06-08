class Solution {
public:
    int minimumRightShifts(vector<int>& a) {
        if (is_sorted(a.begin(), a.end())) return 0;
        int n = a.size();
        for (int i=n-1; i>=0; --i) {
            bool ok = true;
            for (int j=1; j<n; ++j)
                if (a[(i+j)%n] < a[(i+j-1+n)%n]) {
                    ok = false;
                    break;
                }
            if (ok) return n-i;
        }
        return -1;
    }
};