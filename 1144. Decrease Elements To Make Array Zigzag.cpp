class Solution {
public:
    int movesToMakeZigzag(vector<int>& a) {
        int f = 0, nowf = a[0], g = 0, nowg = a[0], n = a.size();
        if (n == 1) return 0;
        
        for (int i=0; i+1<a.size(); ++i) {
            if (!(i & 1) && nowf >= a[i+1]) {
                f += nowf - (a[i+1]-1); 
                nowf = a[i+1];
            } else if ((i&1) && nowf <= a[i+1]) {
                f += a[i+1] - (nowf-1);
                nowf = nowf - 1;
            } else 
                nowf = a[i+1];
            
            if ((i & 1) && nowg >= a[i+1]) {
                g += nowg- (a[i+1]-1); 
                nowg = a[i+1];
            } else if (!(i&1) && nowg <= a[i+1]) {
                g += a[i+1] - (nowg-1);
                nowg = nowg - 1;
            } else 
                nowg = a[i+1];
        }
        return min(f, g);
    }
};