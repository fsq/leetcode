class Solution {
public:
    const int M = 1000000007;
    
    inline int lowbit(int x) {
        return x & (-x);
    }
    
    int sum(const vector<int>& s, int x) {
        int ans = 0;
        for (; x>0; x-=lowbit(x))
            ans += s[x];
        return ans;
    }
    
    void add(vector<int>& s, int x) {
        for (; x<s.size(); x+=lowbit(x))
           ++s[x];
    }
    
    int createSortedArray(vector<int>& a) {
        vector<int> s(*max_element(a.begin(), a.end()) + 1);
        vector<int> d(s.size());
        int ans = 0;
        for (int i=0; i<a.size(); ++i) {
            int v = sum(s, a[i]-1);
            ans = (ans + min(v, i - v - d[a[i]])) % M;
            ++d[a[i]];
            add(s, a[i]);
        }
        return ans;
    }
};