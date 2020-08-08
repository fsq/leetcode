class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        a.push_back(INT_MAX);
        int p = 1, ans = 1, i = 0, x = 1;
        while (p <= k) {
            if (a[i]==x)
                ++x, ++i;
            else
                ans=x, ++x, ++p;
        }
        return ans;
    }
};