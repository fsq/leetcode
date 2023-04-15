class LUPrefix {
public:
    vector<bool> a;
    int i = 0;

    LUPrefix(int n) {
        a.resize(n+1);
        a[0] = true;
    }
    
    void upload(int video) {
        a[video] = true;
        while (i+1<a.size() && a[i+1]) {
            ++i;
        }
    }
    
    int longest() {
        return i;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */