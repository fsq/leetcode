class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int target) {
        if (target==0) return 0;
        if (target % gcd(a, b) != 0) return -1;

        int rl = target + 5*max(a, b);
        vector<vector<int>> vis(rl+1, vector<int>(2));
        unordered_set<int> no(forbidden.begin(), forbidden.end());
        queue<vector<int>> q;
        q.push({0, 0});
        for (int stp=1; q.size(); ++stp)
            for (int t=q.size(); t; --t) {
                auto pr = q.front(); q.pop();
                int x = pr[0];
                if (!pr[1]) {
                    int y = x - b;
                    if (y >=0 && !vis[y][1] && !no.count(y)) {
                        if (!(y > target && a>b)) {
                            q.push({y, 1});
                            vis[y][1] = true;
                            if (y==target) return stp;
                        }
                    }
                }
                {
                    int y = x + a;
                    if (y <= rl && !vis[y][0] && !no.count(y)) {
                        q.push({y, 0});
                        vis[y][0] = true;
                        if (y==target) return stp;
                    }
                }
            }
        return -1;
    }
};