class Solution {
public:
    bool isV(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long beautifulSubstrings(string st, int k) {
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> m; // [prefix_sum][vi]
        m[0][0] = 1;
        for (int s=0,v=0,i=1; i<=st.size(); ++i) {
            char c = st[i-1];
            s += isV(c) ? 1 : -1;
            // (vi-vj)^2 %k == (vi-vj)%k ^2 %k
            // == (vi%k-vj%k)^2 %k ==0
            v = (v + isV(c)) % k;
            for (auto [vj, cnt] : m[s])
                if ((v-vj)*(v-vj)%k == 0)
                    ans += cnt;
            
            ++m[s][v];
        }
        return ans;
    }
};