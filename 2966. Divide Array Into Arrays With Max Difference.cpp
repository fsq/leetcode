class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i=0; i<a.size(); i+=3) {
            if (a[i]+k<a[i+2]) return {};
            ans.push_back({a[i], a[i+1], a[i+2]});
        }
        return ans;
    }
};