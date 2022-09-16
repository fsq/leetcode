class Solution {
public:
    
    class Node {
    public:
        int maxLen = 1, ll = 1, lr = 1, len = 1;
        char cl, cr;
    };
    
    vector<Node> t;
    
    void refresh(int i) {
        Node &n = t[i], &l = t[i*2], &r = t[i*2+1];
        
        n.cl = l.cl;
        n.ll = l.ll + (l.ll==l.len && l.cl==r.cl ? r.ll : 0);
        n.cr = r.cr;
        n.lr = r.lr + (r.lr==r.len && r.cr==l.cr ? l.lr : 0);
        
        n.maxLen = max(l.maxLen, r.maxLen);
        if (l.cr == r.cl) n.maxLen = max(n.maxLen, l.lr+r.ll);
    }
    
    void build(string& s, int index, int l, int r) {
        t[index].len = r - l + 1;
        if (l==r) {
            t[index].cl = t[index].cr = s[l];
        } else {
            int m = (l+r) >> 1;
            build(s, index*2, l, m);
            build(s, index*2+1, m+1, r);
            refresh(index);
        }
    }
    
    void update(int index, int l, int r, int p, int c) {
        if (l == r) {
            t[index].cl = t[index].cr = c;
        } else {
            int m = (l+r) >> 1;
            if (p <= m)
                update(index*2, l, m, p, c);
            else
                update(index*2+1, m+1, r, p, c);
            refresh(index);
        }
    }
    
    vector<int> longestRepeating(string s, string qs, vector<int>& qi) {
        t.resize(s.size()*4);
        build(s, 1, 0, s.size()-1);
        vector<int> ans;
        for (int i=0; i<qs.size(); ++i) {
            update(1, 0, s.size()-1, qi[i], qs[i]);
            ans.push_back(t[1].maxLen);
        }
        return ans;
    }
};