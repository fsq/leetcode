class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        sort(a.begin(), a.end()); // or nth element
        vector<int> ans(a.size());
        int i = 0;
        for (int j=0; j<ans.size(); j+=2)
            ans[j] = a[i++];
        for (int j=1; j<ans.size(); j+=2)
            ans[j] = a[i++];
        return ans;
    }
};