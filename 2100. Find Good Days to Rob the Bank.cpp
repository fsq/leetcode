class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int time) {
        int n = a.size();
        vector<int> inc(n), dec(n);
        dec[0] = 1;
        for (int i=1; i<n; ++i) 
            dec[i] = a[i] <= a[i-1] ? dec[i-1]+1 : 1;
        inc[n-1] = 1;
        for (int i=n-2; i>=0; --i)
            inc[i] = a[i] <= a[i+1] ? inc[i+1]+1 : 1;
        vector<int> ans;
        for (int i=time; i+time<n; ++i)
            if (dec[i]>=time+1 && inc[i]>=time+1)
                ans.push_back(i);
        return ans;
    }
};