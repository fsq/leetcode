class Solution {
public:
    bool canFormArray(vector<int>& a, vector<vector<int>>& b) {
        unordered_map<int, int> m;
        for (int i=0; i<b.size(); ++i)
            m[b[i][0]] = i;
        for (int j, i=0; i<a.size(); ) {
            if (!m.count(a[i])) return false;
            int k = m[a[i]];
            for (int j=0; j<b[k].size(); ++j)
                if (a[i+j] != b[k][j]) return false;
            i += b[k].size();
        }
        return true;
    }
};