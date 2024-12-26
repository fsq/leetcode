class Solution {
public:
    int minimumLevels(vector<int>& a) {
        int k = count(a.begin(), a.end(), 0);
        int s = 0;
        int n = a.size();
        for (int i=0; i+1<a.size(); ++i) {
            s += a[i];
            int x = s - (i+1-s);
            int y = (n-k-s) - (k-(i+1-s));
            if (x > y) return i+1;
        }
        return -1;
    }
};