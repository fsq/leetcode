class Solution {
public:
    vector<long long> findXSum(vector<int>& a, int k, int sz) {
        unordered_map<int, int> freq;
        set<pair<long long, long long>, greater<pair<long long, long long>>> st;
        long long tot = 0;     // maintain sum of first [0..kth-1] pairs
        auto kth = st.begin(); // maintain ptr to sz-th pair

        auto insert = [&](long long f, long long x) {
            st.insert({f, x});
            if (st.size() <= sz) {
                kth = st.end();
                tot += f * x;
            } else if (kth==st.end() || (f>kth->first || f==kth->first && x>kth->second)) {
                tot += f * x;
                kth = prev(kth);
                tot -= kth->first * kth->second;
            }
        };

        auto remove = [&](decltype(st.begin()) it) {
            if (it == kth) {
                kth = next(kth);
                st.erase(it);
            } else {
                auto [f, x] = *it;
                st.erase(it);
                if (kth==st.end() || (f>kth->first || f==kth->first && x>kth->second)) {
                    tot -= f * x;
                    if (kth != st.end()) {
                        tot += kth->first * kth->second;
                        kth = next(kth);
                    }
                }
            }
        };

        vector<long long> ans;
        for (int i=0; i<a.size(); ++i) {
            // include a[i] to set
            auto it = st.find({freq[a[i]]++, a[i]});
            if (it != st.end()) {
                remove(it);
            }
            insert(freq[a[i]], a[i]);

            // exclude a[i-k] if in the set
            if (i >= k) {
                it = st.find({freq[a[i-k]]--, a[i-k]});
                if (it != st.end()) {
                    remove(it);
                    insert(freq[a[i-k]], a[i-k]);
                }
            }

            if (i>=k-1) {
                ans.push_back(tot);
            }
        }
        return ans;
    }
};