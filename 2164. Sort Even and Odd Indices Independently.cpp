class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> a, b;
        for (int i=0; i<nums.size(); ++i)
            if (i&1)
                b.push_back(nums[i]);
            else 
                a.push_back(nums[i]);
        sort(b.rbegin(), b.rend());
        sort(a.begin(), a.end());
        vector<int> ans(nums.size());
        for (int i=0; i<a.size(); ++i) ans[i*2] = a[i];
        for (int i=0; i<b.size(); ++i) ans[i*2+1] = b[i];
        return ans;
    }
};