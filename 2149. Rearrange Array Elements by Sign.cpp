class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int> ans(a.size());
        int p=0, n=1;
        for (auto x : a)
            if (x < 0) {
                ans[n] = x;
                n += 2;
            } else {
                ans[p] = x;
                p += 2;
            }
        return ans;
    }
};