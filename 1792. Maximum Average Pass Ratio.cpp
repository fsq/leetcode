class Solution {
public:
    double inc(double b0, double b1) {
        return (b0+1)/(b1+1) - b0/b1;
    }
    
    double maxAverageRatio(vector<vector<int>>& a, int extraStudents) {
        // HAVE TO USE ARRAY INSTEAD OF VECTOR<INT>, OTHERWISE TLE
        priority_queue<pair<double, array<int, 2>>> q;
        double sum = 0;
        for (auto& b : a) {
            sum += b[0]*1.0 / b[1];
            q.push({inc(b[0], b[1]), {b[0], b[1]}});
        }
        while (extraStudents--) {
            auto [add, a] = q.top(); q.pop();
            sum += add;
            ++a[0], ++a[1];
            q.push({inc(a[0], a[1]), {a[0], a[1]}});
        }
        return sum / a.size();
    }
};