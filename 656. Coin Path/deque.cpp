class Solution {
public:
    // https://leetcode.com/problems/coin-path/description/
    // O(n) time sliding window
    // maintain a monotonically increasing deque
    // start from tail to front, then we don't have to care about the lexico order
    
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        if (n==0) return {};
        if (A.back()==-1) return {};
        if (n==1) return {1};
        
        vector<int> g(n, -1);
        
        deque<vector<int>> q;
        q.push_back({0, n-1});
        
        for (int i=n-2; i>=0; --i) 
            if (A[i]!=-1) {
                while (!q.empty() && q.front()[1]>i+B) q.pop_front();
                if (q.empty()) return {};

                auto &pre = q.front();
                vector<int> nxt = {pre[0]+A[i], i};
                g[i] = pre[1];

                while (!q.empty() && nxt<q.back()) q.pop_back();
                q.push_back(nxt);
            }
        if (g[0]==-1) return {};

        vector<int> ans;
        for (int x=0; x!=-1; x=g[x]) ans.push_back(x+1);
        return ans;
        
    }
};