class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& a) {
        int mxt=a[0][1], id=a[0][0];
        for (int i=1; i<a.size(); ++i) {
            int t = a[i][1] - a[i-1][1];
            if (t > mxt || t==mxt && a[i][0]<id) {
                mxt = t;
                id = a[i][0];
            }
        }
        return id;
    }
};