class Solution {
public:
    unordered_map<int, int> first;

    bool ok(vector<int>& a, vector<int>& change, int time) {
        int spare = 0;
        long long left = accumulate(a.begin(), a.end(), 0ll) + a.size();
        multiset<int> bank;
        
        for (int i=time; i>=0; --i) {

            int x = change[i] - 1;
            if (i==first[x] && a[x]!=0) {
                bank.insert(a[x]);
                left -= a[x]+1;
                if (spare > 0) {
                    --spare;
                } else {
                    ++spare;
                    int y = *bank.begin();
                    bank.erase(bank.begin());
                    left += y+1;
                }
            } else {
                ++spare;
            }
        }
        return spare >= left;
    }

    int earliestSecondToMarkIndices(vector<int>& a, vector<int>& change) {
        int l=0, r=change.size()-1;
        for (int i=0; i<change.size(); ++i)
            if (!first.count(change[i]-1)) {
                first[change[i]-1] = i;
            }
        
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