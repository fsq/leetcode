class Solution {
public:
    double trimMean(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        return accumulate(a.begin()+n/20, a.end()-n/20, 0) / (n * 0.9);
    }
};