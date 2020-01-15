class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            int x=a>>i&1, y=b>>i&1, z=c>>i&1;
            if (z==0)
                ans += x + y;
            else 
                ans += (x+y) == 0;
        }
        return ans;
    }
};