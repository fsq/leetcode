class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n = a.size();
        if (n<3) return false;
        int i = 0;
        while (i+1<n && a[i+1]>a[i]) ++i;
        
        if (i==0 || i==n-1) return false;
        
        while (i+1<n) 
            if (a[i+1]>=a[i])
                return false;
            else ++i;
        return true;
    }
};