class Solution {
public:
    vector<int> assignTasks(vector<int>& ss, vector<int>& tasks) {
        set<vector<int>> a, b;
        for (int i=0; i<ss.size(); ++i) {
            a.insert({ss[i], i});
        }
        int t = 0;
        vector<int> ans(tasks.size());
        
        for (int i=0; i<tasks.size(); ++i) {
            beg:
            while (b.size() && (*b.begin())[0] <= t) {
                auto p = *b.begin();
                a.insert({p[1], p[2]});
                b.erase(b.begin());
            }
            if (a.empty()) {
                t = (*b.begin())[0];
                goto beg;
            } else {
                auto p = *a.begin();
                a.erase(a.begin());
                b.insert({t + tasks[i], p[0], p[1]});
                ans[i] = p[1];
                if (t <= i) ++t;
            }
        }
        return ans;
    }
};