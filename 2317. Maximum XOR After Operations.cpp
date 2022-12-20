class Solution {
public:
    int maximumXOR(vector<int>& a) {
        int ans = 0;
        for (auto x : a)
            ans |= x;
        return ans;
    }
};