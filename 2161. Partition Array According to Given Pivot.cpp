class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int pivot) {
        vector<int> ans(a.size(), pivot);
        for (int j=0, k=a.size()-1, i=0; i<a.size(); ++i) {
            if (a[i]<pivot) ans[j++] = a[i];
            if (a[a.size()-i-1]>pivot) ans[k--] = a[a.size()-i-1];
        }
        return ans;
    }
};