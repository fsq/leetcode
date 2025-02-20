class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        // case1: four corners of rectangle. #1 of the 4 corner has to be multiply of 4.
        // So we can just make them equal by any means.
        for (int i=0; i<n/2; ++i) {
            for (int j=0; j<m/2; ++j) {
                int x = a[i][j] + a[n-i-1][j] + a[i][m-j-1] + a[n-i-1][m-j-1];
                ans += min(x, 4-x);
            }
        }

        // case2: center of the grid, has to be 0, since #1 in the rest of grid is even.
        if ((n&1) && (m&1)) {
            ans += a[n/2][m/2];
        }

        int zo = 0, oo = 0;  // 0-1, 1-1
        // case3: middle row
        if (n & 1) {
            for (int j=0; j<m/2; ++j) {
                int x = a[n/2][j], y = a[n/2][m-j-1];
                if (x ^ y) {
                    ++zo;
                } else if (x == 1) {
                    ++oo;
                }
            }
        }
        // case4: middle column
        if (m & 1) {
            for (int i=0; i<n/2; ++i) {
                int x = a[i][m/2], y = a[n-i-1][m/2];
                if (x ^ y) {
                    ++zo;
                } else if (x == 1) {
                    ++oo;
                }
            } 
        }
        // if there is a single pair of 11, change one 01 to 11 to make it multiple of 4.
        if (oo & 1) {
            if (zo) {
                zo--;
                ans++;
            } else {
                ans += 2;
            }
        }
        ans += zo;
        return ans;
    }
};.c