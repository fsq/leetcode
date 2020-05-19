class Solution {
public:
    
    string largestNumber(vector<int>& a, int target) {
        vector<int> l(target+1, -1);
        a.insert(a.begin(), 0);
        l[0] = 0;
        for (int i=1; i<=target; ++i) 
            for (int j=1; j<=9; ++j)
                if (i-a[j]>=0 && l[i-a[j]]!=-1)
                    l[i] = max(l[i], l[i-a[j]]+1);
        
        if (l[target]==-1) return "0";
        string ans;
        while (target) {
            int maxl = 0, k = 0;
            for (int i=1; i<=9; ++i)
                if (target>=a[i] && l[target-a[i]]!=-1 && l[target-a[i]]+1>=maxl) {
                    maxl = l[target-a[i]] + 1;
                    k = i;
                }
            ans.push_back('0' + k);
            target -= a[k];
        }
        return ans;
    }
};