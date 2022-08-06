class Solution {
public:
    vector<int> find(unordered_map<int, int> c) {
        int m1=0, m2=0, a, b;
        for (auto x : c)
            if (x.second >= m1) {
                m2 = m1;
                b = a;
                m1 = x.second;
                a = x.first;
            } else if (x.second > m2) {
                b = x.first;
                m2 = x.second;
            }
        return {a, b};
    }
    
    int minimumOperations(vector<int>& a) {
        unordered_map<int, int> c1, c2;
        int mx1=0, mx2=0;
        for (int i=0; i<a.size(); ++i)
            if (i & 1) 
                ++c2[a[i]];
            else 
                ++c1[a[i]];
        vector<int> x = find(c1), y = find(c2);
        if (x[0] != y[0])
            return a.size() - c1[x[0]] - c2[y[0]];
        else
            return a.size() - max(c1[x[0]]+c2[y[1]], c1[x[1]]+c2[y[0]]);
    }
};