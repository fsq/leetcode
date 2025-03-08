class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int multiplier) {
        while (k--) {
            size_t i = min_element(a.begin(), a.end()) - a.begin();
            a[i] *= multiplier;
        }
        return a;
    }
};