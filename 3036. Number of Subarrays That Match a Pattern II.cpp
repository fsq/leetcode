class Solution {
public:
    int sign(int x) {
        if (x == 0) return 0;
        return x > 0 ? 1 : -1;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& a) {
        // construct pattern + <divider> + string
        int pl = a.size();
        a.push_back(10086);
        for (int i=1; i<nums.size(); ++i)
            a.push_back(sign(nums[i] - nums[i-1]));
        
        vector<int> next(a.size());
        int i=1, j=0;
        while (i < a.size())
            if (a[i] == a[j]) {
                next[i++] = ++j;
            } else if (j > 0) {
                j = next[j-1];
            } else {
                ++i;
            }
        return count(next.begin(), next.end(), pl);
    }
};