class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return {};
        vector<long long> ans;
        for (long long x=2; ans.empty() || finalSum>ans.back(); x+=2) {
            ans.push_back(x);
            finalSum -= x;
        }
        ans.back() += finalSum;
        return ans;
    }
};