using ld = double;
class Solution {
public:
    vector<ld> A;
    ld tot_k = 0, tot;
    int n;
    
    void dfs(vector<int>& balls, int r1, int r2, int k1, int k2, ld s1, ld s2, int id) {
        if (id==balls.size()) {
            ld kind = A[n/2] / s1 * A[n/2] / s2;
            tot += kind;
            if (k1==k2) tot_k += kind;
        } else {
            for (int u1=max(0, balls[id]-r2); u1<=min(r1, balls[id]); ++u1) {
                int u2 = balls[id] - u1;
                int k1t = k1 + (u1>0), k2t = k2 + (u2>0);
                dfs(balls, r1-u1, r2-u2, k1t, k2t, s1*A[u1], s2*A[u2], id+1);
            }
        }
    }
    
    double getProbability(vector<int>& balls) {
        n = accumulate(balls.begin(), balls.end(), 0);
        A.resize(n+1);
        A[0] = 1;
        for (int i=1; i<=n; ++i) A[i] = A[i-1] * i;
        dfs(balls, n/2, n/2, 0, 0, 1, 1, 0);
        return tot_k / tot;
    }
};