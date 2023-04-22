class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> a = {pref[0]};
        int s = a[0];
        for (int i=1; i<pref.size(); ++i) {
            a.push_back(s ^ pref[i]);
            s ^= a[i];
        }
        return a;
    }
};