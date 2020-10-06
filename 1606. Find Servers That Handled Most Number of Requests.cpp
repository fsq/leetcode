class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrv, vector<int>& load) {
        set<int> av;
        set<pair<int,int>> busy;
        vector<int> done(k);
        for (int i=0; i<k; ++i) av.insert(i);
        
        for (int i=0; i<arrv.size(); ++i) {
            int t = arrv[i], cost = load[i];
            while (busy.size() && busy.begin()->first<=t) {
                av.insert(busy.begin()->second);
                busy.erase(busy.begin());
            }
            if (av.empty()) continue;
            auto it = av.lower_bound(i % k);
            if (it==av.end()) it = av.begin();
            ++done[*it];
            busy.insert({t+cost, *it});
            av.erase(it);
        }
        
        vector<int> ans;
        int mx = 0;
        for (int i=0; i<k; ++i)
            if (done[i]==mx) {
                ans.push_back(i);
            } else if (done[i]>mx) {
                mx = done[i];
                ans = {i};
            }
        return ans;
    }
};