class Solution {
public:
    vector<int> threeEqualParts(vector<int>& a) {
        int n = a.size();
        int cnt = count(a.begin(), a.end(), 1);
        if (cnt==0) return {0, n-1};
        if (cnt%3) return {-1, -1};
        
        int k = cnt / 3;
        int tail = 0;
        for (int i=n-1; !a[i]; --i) ++tail;
        
        int i = 0;
        for (int c=0; c<k; ++i)
            c += a[i];
        i += tail - 1;
        
        int j = i+1;
        for (int c=0; c<k; ++j)
            c += a[j];
        j += tail - 1;

        for (int x=i, y=j, z=n-1; x>=0 && y>i && z>j; --x,--y,--z)
            if (!(a[x]==a[y] && a[y]==a[z]))
                return {-1, -1};
        
        return {i, j+1};
        
    }
};