class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<vector<int>> s;
        for (int i=0; i<a.size(); ++i)
            s.push_back({a[i], b[i]});
        sort(s.begin(), s.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]+a[1] > b[0]+b[1]; 
        });
        int x=0, y=0;
        for (int i=0; i<s.size(); ++i)
            if (!(i & 1))
                x += s[i][0];
            else
                y += s[i][1];
        if (x == y) return 0;
            else    return (x>y ? 1 : -1);
    }
};
