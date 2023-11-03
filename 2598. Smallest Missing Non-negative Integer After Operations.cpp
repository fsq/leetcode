class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> r(value);
        for (auto x : nums) 
            ++r[(x%value+value)%value];
        int mn=INT_MAX, b=0;
        for (int i=0; i<value; ++i)
            if (r[i]<mn) {
                mn = r[i];
                b = i;
            }
        return value*r[b]+b;
    }
};