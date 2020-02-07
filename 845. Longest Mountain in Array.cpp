class Solution {
public:
    int longestMountain(vector<int>& a) {
        int ans = 0;
        for (int j,k,i=0; i+2<a.size(); i=k) 
            if (a[i+1]<=a[i]) 
                k = i+1;
            else {
                for (j=i+1; j<a.size() && a[j]>a[j-1]; ++j);
                for (k=j; k<a.size() && a[k]<a[k-1]; ++k);
                if (k>j && j>i) {
                    ans = max(ans, k-i);
                    --k;
                }
            }
        return ans;
    }
};