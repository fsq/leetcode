class Solution {
public:
    vector<int> s;
    
    inline int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int delta) {
        for (; x<s.size(); x+=lowbit(x)) 
            s[x] += delta;
    }
    
    int query(int x) {
        int sum = 0;
        for(; x>0; x-=lowbit(x))
            sum += s[x];
        return sum;
    }
    
    vector<int> processQueries(vector<int>& a, int m) {
        s.resize(2*m+1);
        vector<int> p(m+1); //[m+1..2m]
        for (int i=m+1; i<=2*m; ++i) {
            p[i-m] = i;
            add(i, 1);
        }
        int nxt = m;
        vector<int> ans;
        for (auto x : a) {
            ans.push_back(query(p[x])-1);
            add(p[x], -1);
            p[x] = nxt--;
            add(p[x], 1);
        }
        return ans;
    }
};