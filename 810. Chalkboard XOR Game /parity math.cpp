class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int s = 0;
        for(auto x : nums) s^=x;
        return s==0 || !(nums.size() & 1);
    }
};