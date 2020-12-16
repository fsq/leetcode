class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& a) {
        vector<int> ans(a.size());
        int prev = 0, after = accumulate(a.begin()+1, a.end(), 0);
        for (int i=0; i<a.size(); ++i) {
            ans[i] = i*a[i] - prev + after - (a.size()-1-i)*a[i];
            prev += a[i];
            if (i+1<a.size())
                after -= a[i+1];
        }
        return ans;
    }
};