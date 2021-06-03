class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i=0; i<tasks.size(); ++i) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        set<vector<int>> st;
        vector<int> ans;
        long long t = 0;
        for (int i=0; i<tasks.size() || st.size(); ) {
            if (!st.size())
                t = max<long long>(t, tasks[i][0]);
            while (i<tasks.size() && tasks[i][0] <= t) {
                st.insert({tasks[i][1], tasks[i][2]});
                ++i;
            }
            auto pr = *st.begin();
            st.erase(st.begin());
            
            ans.push_back(pr[1]);
            t += pr[0];
        }
        return ans;
    }
};