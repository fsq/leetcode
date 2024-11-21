class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) return y - x;
        int u = x + (x - y);
        unordered_map<int, int> m;
        m[x] = 0;
        queue<int> q;
        q.push(x);
        while (q.size()) {
            int x = q.front(); q.pop();
            vector<int> nx;
            if (x+1<u && !m.count(x+1)) nx.push_back(x+1);
            if (x-1>=y) nx.push_back(x-1);
            if (x%11==0) nx.push_back(x / 11);
            if (x%5==0) nx.push_back(x / 5);
            for (auto n : nx) 
                if (!m.count(n)) {
                    if (n == y) return m[x] + 1;
                    q.push(n);
                    m[n] = m[x] + 1;
                }
        }
        return -1;
    }
};