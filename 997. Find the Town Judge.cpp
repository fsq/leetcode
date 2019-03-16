class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        vector<int> ind(n+1), oud(n+1);
        for (auto& pr : a) {
            ++ind[pr[1]];
            ++oud[pr[0]];
        }
        for (int i=1; i<=n; ++i)
            if (ind[i]==n-1 && oud[i]==0)
                return i;
        return -1;
    }
};