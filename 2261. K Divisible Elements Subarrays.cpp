class Tree {
public:
    int cnt = 0;
    unordered_map<int, Tree*> nxt;
};

class Solution {
public:
    
    int insert(Tree& t, vector<int>& a, int i, int k, int p) {
        if (i==a.size() || (a[i]%p==0 && k==0)) return 0;
        if (t.nxt[a[i]] == nullptr) t.nxt[a[i]] = new Tree();
        return (++t.nxt[a[i]]->cnt==1 ? 1 : 0) + insert(*t.nxt[a[i]], a, i+1, k-(a[i]%p==0), p);
    }
    
    int countDistinct(vector<int>& a, int k, int p) {
        Tree t;
        int ans = 0;
        for (int i=0; i<a.size(); ++i)
            ans += insert(t, a, i, k, p);
        return ans;
    }
};