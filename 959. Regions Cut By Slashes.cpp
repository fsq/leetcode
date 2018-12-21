class Solution {
public:
    vector<int> fa;
    int n;
    
    int find(int x) {
        return fa[x]==x ? x :fa[x]=find(fa[x]);
    }
    
    int encode(int i, int j, int c) {
        return (i*n+j)*4 + c - 1;
    }
    
    void merge(int x, int y) {
        int fx=find(x), fy=find(y);
        if (fx!=fy)
            fa[fx] = fy;
    }
    
    int regionsBySlashes(vector<string>& a) {
        n = a.size();
        fa.resize(n*n*4);
        iota(fa.begin(), fa.end(), 0);
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                if (a[i][j]=='\\') {
                    merge(encode(i,j,1), encode(i,j,2));
                    merge(encode(i,j,3), encode(i,j,4));
                } else if (a[i][j]=='/') {
                    merge(encode(i,j,1), encode(i,j,4));
                    merge(encode(i,j,2), encode(i,j,3));
                } else {
                    merge(encode(i,j,1), encode(i,j,2));
                    merge(encode(i,j,2), encode(i,j,3));
                    merge(encode(i,j,3), encode(i,j,4));
                }
                if (j+1<n) merge(encode(i,j,2), encode(i,j+1,4));
                if (i+1<n) merge(encode(i,j,3), encode(i+1,j,1));
            }
        
        int cc = 0;
        for (int i=0; i<fa.size(); ++i) 
            cc += fa[i] == i;
        
        return cc;
    }
};