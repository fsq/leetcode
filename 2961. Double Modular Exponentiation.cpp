class Solution {
public:

    int pow(int x, int p, int m) {
        if (p==0) return 1;
        if (p==1) return x%m;
        int s = pow(x, p>>1, m);
        s = s * s % m;
        if (p & 1) {
            s = s * x % m;
        }
        return s;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i=0; i<variables.size(); ++i) {
            auto& ar = variables[i];
            int a = ar[0], b = ar[1], c = ar[2], d= ar[3];
            int x = pow(a, b, 10);
            int y = pow(x, c, d);
            if (y == target) ans.push_back(i);
        }
        return ans;
    }
};