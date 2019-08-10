class SnapshotArray {
public:
    vector<vector<pair<int,int>>> a;
    int id = 0;

    SnapshotArray(int length) {
        a = vector<vector<pair<int,int>>>(length, vector<pair<int,int>>{{0, 0}});
    }
    
    void set(int index, int val) {
        if (a[index].back().first == id)
            a[index].back().second = val;
        else
            a[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto& s = a[index];
        int i = upper_bound(s.begin(), s.end(), pair<int,int>{snap_id, INT_MAX}) - s.begin() - 1;
        return s[i].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */