class Solution {
public:
    int sign(int x) {
        if (x == 0) return 0;
        return x > 0 ? 1 : -1;
    }

    int countMatchingSubarrays(vector<int>& a, vector<int>& b) {
        int ans = 0;
        for (int i=0; i+b.size()<a.size(); ++i) {
            bool ok = true;
            for (int j=0; j<b.size(); ++j)
                if (sign(a[i+j+1] - a[i+j]) != b[j]) {
                    ok = false;
                    break;
                }
            if (ok) ++ans;
        }
        return ans;
    }
};