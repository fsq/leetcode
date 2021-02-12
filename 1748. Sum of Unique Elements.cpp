class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> a(101);
        for (auto x : nums) ++a[x];
        int ans = 0;
        for (int i=1; i<=100; ++i)
            if (a[i]==1) 
                ans += i;
        return ans;
    }
};