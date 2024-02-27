class Solution {
public:

    bool ok(vector<int> a, vector<int>& change, int time) {
        int spare = 0, num_done = 0;
        unordered_map<int, int> last;
        for (int i=time; i>=0; --i)
            if (!last.count(change[i]-1))
                last[change[i]-1] = i;
        
        for (int i=0; i<=time; ++i) {
            int x = change[i] - 1;
            ++spare;
            if (i==last[x]) {
                if (spare < a[x]) return false;
                spare -= a[x];
                a[x] = 0;
                ++num_done;
            } 

        }
        return num_done == a.size();
    }

    int earliestSecondToMarkIndices(vector<int>& a, vector<int>& change) {
        for (auto& x : a) ++x;
        int l=0, r=change.size()-1;
        while (l < r) {
            int mid = (l+r) >> 1;
            if (ok(a, change, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (ok(a, change, l))
            return l+1;
        else
            return -1;
    }
};