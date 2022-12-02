class Solution {
public:
    
    int minMaxGame(vector<int>& a) {
        if (a.size()==1) return a[0];
        vector<int> b;
        for (int i=0; i<a.size()/2; ++i)
            if (i & 1) {
                b.push_back(max(a[i*2], a[i*2+1]));
            } else {
                b.push_back(min(a[i*2], a[i*2+1]));
            }
        return minMaxGame(b);
    }
};