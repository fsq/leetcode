class Solution {
public:
    vector<int> applyOperations(vector<int>& a) {
        for (int i=0; i+1<a.size(); ++i)
            if (a[i]==a[i+1]) {
                a[i] *= 2;
                a[i+1] = 0;
            }
        int i, j;
        for (i=0, j=0; j<a.size(); ++i)
            if (a[i]==0) {
                while (j<a.size() && a[j]==0) ++j;
                if (j==a.size()) break;
                a[i] = a[j];
                a[j++] = 0;
            } else 
                ++j;
        return a;
    }
};