class Solution {
public:
    // DFS solution with bit manipulation
    // search from n to 1 can efficiently reduce branches
    // https://leetcode.com/problems/beautiful-arrangement/description/
    // O(n!) time, O(n) space
    
    int ans = 0;
    
    // vis: bit vector, bit[i]=1 denotes (i+1) is used
    void dfs(int now, int vis,int n) {
        if (now==0) {
            ++ans;
            return;
        }
        for (int i=n; i>=1; --i)
            if ((i%now==0 || now%i==0) && !((vis>>i) & 1)) 
                dfs(now-1, vis|(1<<i), n);
    }
    
    int countArrangement(int N) {
        dfs(N, 0, N);
        return ans;
    }
};