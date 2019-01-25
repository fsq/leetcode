class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for (int k=n; k>=1; --k) {
            int i = find(a.begin(), a.end(), k) - a.begin();
            if (i != k-1) {
                if (i>0) {
                    ans.push_back(i+1);
                    reverse(a.begin(), a.begin()+i+1);
                }
                ans.push_back(k);
                reverse(a.begin(), a.begin()+k);
            }
        }
        return ans;
    }
};