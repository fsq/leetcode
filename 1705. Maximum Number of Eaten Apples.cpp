class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& d) {
        map<int, int> m;
        int n = a.size(), ans = 0;

        for (int i=0; i<n || m.size(); ++i) {
            if (i<n && a[i] > 0) m[i+d[i]] += a[i];
            if (m.empty()) continue;
            if (m.begin()->first == i)
                m.erase(m.begin());
            if (m.begin()->first > i) {
                --m.begin()->second;
                ++ans;
                if (m.begin()->second == 0) 
                    m.erase(m.begin());
            }
        }
        return ans;
    }
};
