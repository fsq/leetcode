class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int ans = 0;
        for (int i=0; i<(1<<a.size()); ++i) {
            int tot = 0;
            for (int j=0; j<a.size(); ++j)
                if ((i>>j) & 1)
                    tot ^= a[j];
            ans += tot;
        }
        return ans;
    }
};