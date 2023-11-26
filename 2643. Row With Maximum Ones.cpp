class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& a) {
        int id=0, cnt=0;
        for (int i=0; i<a.size(); ++i) {
            int tot = accumulate(a[i].begin(), a[i].end(), 0);
            if (tot > cnt) {
                cnt = tot;
                id = i;
            }
        }
        return {id, cnt};
    }
};