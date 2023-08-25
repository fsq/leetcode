class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& a, int k) {
        sort(a.begin(), a.end(), [k](vector<int>& a, vector<int>& b) {
            return a[k] > b[k];
        });
        return a;
    }
};