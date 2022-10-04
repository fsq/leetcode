class Solution {
public:
    
    void add(map<long long, int>& m, long long& k) {
        if (k==0 || m.empty()) return;
        long long cnt = m.begin()->second, x = m.begin()->first;
        if (m.size()>1) {
            auto nx = next(m.begin())->first;
            if (k >= (nx-x)*cnt) {
                m[nx] += cnt;
                k -= (nx-x)*cnt;
                m.erase(m.begin());
                add(m, k);
                return;
            } 
        }
        auto ad = k / cnt, rm = k % cnt;
        k = 0;
        m.erase(m.begin());   
        if (rm) m[x+ad+1] += rm;
        if (cnt>rm) m[x+ad] += cnt - rm;
    }
    
    long long maximumBeauty(vector<int>& a, long long k, int target, long long full, long long partial) {
        map<long long, int> m; // partial
        multiset<long long, std::less<long long>> st; // full
        sort(a.rbegin(), a.rend());
        for (int i=0; i<a.size(); ++i)
            if (target-a[i]>k) 
                m[a[i]]++;
            else {
                st.insert(a[i]);
                k -= max<long long>(0, target - a[i]);
            }
        
        if (m.empty()) {
            return max(st.size()*full, a.back()<target? ((st.size()-1)*full+partial*(target-1)):0);
        }
        
        add(m, k);
        
        long long ans = st.size() * full + m.begin()->first * partial;
        while (st.size() && *st.begin()<target) {
            k += target - *st.begin();
            ++m[*st.begin()];
            st.erase(st.begin());
            add(m, k);
            ans = max<long long>(ans, st.size() * full + m.begin()->first * partial);
        }
        return ans;
    }
};