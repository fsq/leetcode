class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num & 0x55555555) == num) && ((num & (num-1))==0) && num>0;
    }
};