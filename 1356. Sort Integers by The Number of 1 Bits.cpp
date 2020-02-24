class Solution {
public:
    
    int count(int x) {
        int s = 0;
        while (x) {
            s += x & 1;
            x >>= 1;
        }
        return s;
    }
    
    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(), a.end(), [&](int x, int y) {
            int s = count(x), t = count(y);
            return s < t || s==t && x<y;
        });
        return a;
    }
};