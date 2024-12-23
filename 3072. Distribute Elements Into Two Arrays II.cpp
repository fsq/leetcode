class Solution {
public:
    inline int lowbit(int x) {
        return x & -x;
    }
    vector<int> resultArray(vector<int>& a) {
        auto ta = a;
        sort(ta.begin(), ta.end());
        ta.resize(unique(ta.begin(), ta.end()) - ta.begin());
        unordered_map<int, int> m;
        for (int i=0; i<ta.size(); ++i) m[ta[i]] = i+1;
        vector<int> sa(ta.size()+1), sb(ta.size()+1);
        int ca=0, cb=0;
        vector<int> arr1, arr2;
        auto insert = [&](vector<int>& s, int x) {
            for (; x<s.size(); x+=lowbit(x)) ++s[x];
        };
        auto insert1 = [&](int x) {
            insert(sa, m[x]);
            ++ca;
            arr1.push_back(x);
        };
        auto insert2 = [&](int x) {
            insert(sb, m[x]);
            ++cb;
            arr2.push_back(x); 
        };
        auto sum = [&](vector<int>& s, int x) {
            int ret = 0;
            for (int i=m[x]; i; i-=lowbit(i)) ret += s[i];
            return ret;
        };
        insert1(a[0]);
        insert2(a[1]);
        for (int i=2; i<a.size(); ++i) {
            int x = a[i];
            int g1 = ca - sum(sa, x);
            int g2 = cb - sum(sb, x);
            if (g1 < g2 || (g1==g2 && ca>cb)) {
                insert2(x);
            } else {
                insert1(x);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};