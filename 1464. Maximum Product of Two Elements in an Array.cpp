class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=0, m2=0;
        for (auto x : nums)
            if (x >= m1) {
                m2 = m1;
                m1 = x;
            } else if (x > m2)
                m2 = x;
        return (m1-1) * (m2-1);
    }
};