/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    
    int count(Sea& sea, vector<int> a, vector<int> b) {
        if (a[0]>b[0] || a[1]>b[1])
            return 0;
        else if (a == b)
            return sea.hasShips(a, b);
        else {
            if (!sea.hasShips(b, a)) return 0;
            int mx = (a[0]+b[0]) >> 1, my = (a[1]+b[1]) >> 1;
            int tl = count(sea, {a[0], my+1}, {mx, b[1]});
            int tr = count(sea, {mx+1, my+1}, b);
            int bl = count(sea, a, {mx, my});
            int br = count(sea, {mx+1, a[1]}, {b[0], my});
            int ans = tl + tr + bl + br;
            return ans;
        }
    }
    
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return count(sea, bottomLeft, topRight);
    }
};