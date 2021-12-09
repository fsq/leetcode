class LockingTree {
public:
    vector<int> fa, lk;
    vector<vector<int>> e;
    int n;
    
    LockingTree(vector<int>& parent) {
        n = parent.size();
        fa = parent;
        e.resize(n);
        lk.resize(n);
        for (int i=1; i<parent.size(); ++i) {
            e[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (lk[num] == 0) {
            lk[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (lk[num] == user) {
            lk[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (!lk[num] && HasLockedDesc(num) && !HasLockedAnce(num)) {
            UnlockAll(num);
            lk[num] = user;
            return true;
        }
        return false;
    }
    
    bool HasLockedDesc(int x) {
        if (lk[x]) return true;
        for (auto y : e[x])
            if (HasLockedDesc(y))
                return true;
        return false;
    }
    
    bool HasLockedAnce(int x) {
        if (x == -1) return false;
        return (lk[x] || HasLockedAnce(fa[x]));
    }
    
    void UnlockAll(int x) {
        lk[x] = 0;
        for (auto y : e[x]) UnlockAll(y);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */