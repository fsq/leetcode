class Solution {
public:
    vector<int> findPeaks(vector<int>& a) {
        vector<int> ans;
        for (int i=1; i+1<a.size(); ++i)
            if (a[i]>a[i-1] && a[i]>a[i+1])
                ans.push_back(i);
        return ans;
    }
};