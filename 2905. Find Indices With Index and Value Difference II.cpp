class Solution {
public:
    vector<int> findIndices(vector<int>& a, int id, int vd) {
        int mini = 0, maxi = 0;
        for (int i=id; i<a.size(); ++i) {
            int j = i - id;
            if (a[j] < a[mini]) {
                mini = j;
            }
            if (a[j] > a[maxi]) {
                maxi = j;
            }
            if (a[i] - a[mini] >= vd) {
                return {mini, i};
            }
            if (a[maxi] - a[i] >= vd) {
                return {maxi, i};
            }
        }
        return {-1, -1};
        
    }
};