class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (auto x : A) ++m[x];
        if (m.count(0)) ans = vector<int>(m[0], 0);
        for (int i=1; i<=10000; ++i)
            if (m.count(i) || m.count(-i))
                ans.insert(ans.end(), m[i]+m[-i], i*i);
        return ans;
    }
};