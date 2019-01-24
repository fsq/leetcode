class Solution {
public:
    vector<int> ans;
    
    void dfs(int len, int x, int n, int k) {
        if (len==n)
            ans.push_back(x);
        else {
            int last = x % 10;
            if (last-k>=0)
                dfs(len+1, x*10+last-k, n, k);
            if (k!=0 && last+k<10)
                dfs(len+1, x*10+last+k, n, k);
            
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n==1) 
            return {0,1,2,3,4,5,6,7,8,9};
        for (int i=1; i<=9; ++i)
            dfs(1,i,n,k);
        return ans;
    }
};