class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int dx = startPos[0] > homePos[0] ? -1 : 1;
        int dy = startPos[1] > homePos[1] ? -1 : 1;
        for (int i=startPos[0]; i!=homePos[0]; i+=dx)
            ans += rowCosts[i+dx];
        for (int i=startPos[1]; i!=homePos[1]; i+=dy)
            ans += colCosts[i+dy];
        return ans;
    }
};