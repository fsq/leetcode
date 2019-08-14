class MajorityChecker {
public:
    unordered_map<int, vector<int>> p;
    vector<int> a;
    
    MajorityChecker(vector<int>& arr) {
        a = move(arr);
        for (int i=0; i<a.size(); ++i)
            p[a[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
        for (int t=0; t<20; ++t) {
            int i = a[rand()%(right-left+1) + left];
            auto& s = p[i];
            int l = lower_bound(s.begin(), s.end(), left) - s.begin();
            int r = upper_bound(s.begin(), s.end(), right) - s.begin();
            if (r-l >= threshold) return i;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */