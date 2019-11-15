class Solution {
public:
    int binaryGap(int x) {
        int ans = 0;
        for (int pre=-1, i=0; x; x>>=1, ++i) 
            if (x&1) {
                if (pre != -1) ans = max(ans, i-pre);
                pre = i;
            }
        return ans;
    }
};