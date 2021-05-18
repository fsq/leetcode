class Solution {
public:
    int arraySign(vector<int>& a) {
        int neg = 0;
        for (auto x : a)
            if (x == 0) {
                return 0;   
            } else if (x < 0) 
                ++neg;
        return (neg & 1) ? -1 : 1;
    }
};