class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        reverse(a.begin(), a.end());
        int n = a.size();
        vector<int> r(a.size()), q;
        for (int i=0; i<a.size(); ++i) {
            int popped = 0;
            while (!q.empty() && a[q.back()]<a[i]) {
                q.pop_back();
                ++popped;
            }
            r[i] = popped + (!q.empty());
            q.push_back(i);
        }
        reverse(r.begin(), r.end());
        return r;
    }
};