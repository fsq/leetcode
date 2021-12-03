class Solution {
public:
    
    vector<int> dfs(multiset<int>& st, int n) {
        if (n == 1) {
            return {*st.begin() + *next(st.begin())};
        } else {
            int x = *next(st.begin()) - *st.begin();
            for (int sn=-1; sn<=1; sn+=2) {
                unordered_map<int, int> cnt;
                for (auto x : st) ++cnt[x];
                multiset<int> nxt;
                bool ok = true;
                for (auto y : st)
                    if (cnt[y]) {
                        if (!cnt[y+x]) {
                            ok = false;
                            break;
                        }
                        --cnt[y];
                        --cnt[y+x];
                        nxt.insert(sn==1 ? y : y+x);
                    }
                if (ok && nxt.count(0)) {
                    auto remain = dfs(nxt, n-1);
                    if (remain.size()==n-1) {
                        remain.push_back(x * sn);
                        return remain;
                    }
                }
            }
            return {};
        }
    }
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        multiset<int> st(sums.begin(), sums.end());
        return dfs(st, n);
    }
};