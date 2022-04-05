class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> e(n+1);
        vector<int> fin(n+1), ind(n+1);
        
        for (auto& pr : relations) {
            e[pr[0]].push_back(pr[1]);
            ++ind[pr[1]];
        }
        for (int i=1; i<=n; ++i) {
            e[0].push_back(i);
            ++ind[i];
        }        
        queue<int> q;
        q.push(0);

        while (q.size()) {
            int x = q.front(); q.pop();
            for (auto y : e[x]) {
                fin[y] = max(fin[y], fin[x] + time[y-1]);
                if (--ind[y] == 0) 
                    q.push(y);
            }
        }
        
        return *max_element(fin.begin(), fin.end());
    }
};