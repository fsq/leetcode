class Solution {
public:
    int minimumAddedInteger(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> xs = {b[0]-a[2], b[0]-a[1], b[0]-a[0]};
        for (auto x : xs) {
            int i=0, j=0;
            while (i<a.size() && j<b.size())
                if (b[j]-a[i] == x) {
                    ++i, ++j;
                } else {
                    ++i;
                }
            if (j==b.size()) return x;
        }
        return -1;
    }
};