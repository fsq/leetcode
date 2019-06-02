class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        int n = a.size();
        for (int j,i=n-2; i>=0; --i) 
            if (a[i] > a[i+1]) {
                for (j=i+1; j<n && a[i] > a[j]; ++j);
                --j;
                while (a[j]==a[j-1]) --j;
                swap(a[i], a[j]);
                return a;
            }
        return a;
    }
};