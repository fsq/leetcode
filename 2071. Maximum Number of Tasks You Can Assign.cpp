class Solution {
public:
    
    bool ok(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        multiset<int> st(tasks.begin(), tasks.begin()+k);
        for (int i=k-1; i>=0; --i) {
            int w = workers[i];
            if (w >= *st.begin()) {
                st.erase(st.begin());
            } else if (pills) {
                --pills;
                auto it = st.upper_bound(w+strength);
                if (it != st.begin()) {
                    st.erase(prev(it));
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.rbegin(), workers.rend());
        int l = 0, r = min(tasks.size(), workers.size());
        while (l < r) {
            int mid = (l+r+1) >> 1;
            if (ok(tasks, workers, pills, strength, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};