class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> c(5);
        string crk = "croak";
        int ans = 0;
        for (auto x : croakOfFrogs) {
            int i = find(crk.begin(), crk.end(), x) - crk.begin();
            if (i==0)
                ++c[i];
            else {
                if (c[i-1]==0) return -1;
                --c[i-1];
                ++c[i];
            }
            ans = max(ans, accumulate(c.begin(), c.end()-1, 0));
        }
        if (accumulate(c.begin(), c.end()-1, 0)>0) return -1;
        return ans;
    }
};