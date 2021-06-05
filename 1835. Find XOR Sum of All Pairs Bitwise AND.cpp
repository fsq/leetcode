class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        vector<int> a1(32), b1(32);
        for (auto x : a)
            for (int i=0; i<32; ++i)
                if ((x>>i) & 1)
                    ++a1[i];
        for (auto x : b)
            for (int i=0; i<32; ++i)
                if ((x>>i) & 1)
                    ++b1[i];
        int ans = 0;
        for (int i=0; i<32; ++i)
            if (((long long)a1[i]*b1[i]) & 1)
                ans |= 1 << i;
        return ans;
    }
};