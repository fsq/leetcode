class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0, cnt=0;
        for (auto x : nums)
            if (!(x&1) && x%3==0) {
                sum += x;
                ++cnt;
            }
        return cnt ? sum / cnt : 0;
    }
};