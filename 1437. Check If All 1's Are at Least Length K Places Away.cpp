class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        int mn = INT_MAX;
        for (int pre=-1,i=0; i<a.size(); ++i)
            if (a[i]==1) 
                if (pre==-1)
                    pre = i;
                else {
                    mn = min(mn, i-pre-1);
                    pre = i;
                }
        return mn >= k;
    }
};