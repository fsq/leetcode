class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        unordered_set<string> st;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        for (auto& o : obs) st.insert(to_string(o[0]) + "," + to_string(o[1]));
        int x=0, y=0, dir=0, ans = 0;
        for (auto c : cmd)
            if (c == -2) 
                dir = (dir + 3) % 4;
            else if (c == -1)
                dir = (dir + 1) % 4;
            else 
                while (c--) {
                    int tx=x+dx[dir], ty=y+dy[dir];
                    if (st.count(to_string(tx)+","+to_string(ty))) break;
                    x = tx, y = ty;
                    ans = max(ans, x*x+y*y);
                }
        return ans;
    }
};