class Solution {
public:
    bool validPartition(vector<int>& a) {
        int n = a.size();
        vector<int> ok(n+1);
        ok[0] = true;
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && a[i]==a[i-1]) ok[i+1] |= ok[i-1];
            if (i-2>=0 && a[i]==a[i-1] && a[i]==a[i-2]) ok[i+1] |= ok[i-2];
            if (i-2>=0 && a[i]==a[i-1]+1 && a[i]==a[i-2]+2) ok[i+1] |= ok[i-2];
        }
        return ok.back();
    }
};