class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> m;
        for (int i=0; i<b.size(); ++i)
            m[b[i]] = i;
        sort(a.begin(), a.end(), [&](int x, int y) {
           if (m.count(x) && m.count(y))
               return m[x] < m[y];
            else if (m.count(x))
                return true;
            else if (m.count(y))
                return false;
            else return x < y;
        });
        return a;
    }
};