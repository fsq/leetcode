class Solution {
public:
    int minNumberOfHours(int eg, int ex, vector<int>& energy, vector<int>& experience) {
        int req_eg = accumulate(energy.begin(), energy.end(), 0) + 1;
        int req_ex = 0, acc_ex = 0;
        for (auto x : experience) {
            req_ex = max(req_ex, x-acc_ex+1);
            acc_ex += x;
        }
        return max(0, req_eg - eg) + max(0, req_ex - ex);
    }
};