class Allocator {
public:

    vector<int> a;

    Allocator(int n) {
        a.resize(n);
    }
    
    int allocate(int size, int mID) {
        int i,j;
        for (i=0; i<a.size(); )
            if (a[i] != 0)
                ++i;
            else {
                for (j=i; j<a.size() && a[j]==0 && j-i<size; ++j);
                if (j-i==size) {
                    fill(a.begin()+i, a.begin()+j, mID);
                    return i;
                }
                i = j;
            }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (auto& x : a)
            if (x==mID) {
                x = 0;
                ++cnt;
            }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */