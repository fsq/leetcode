class Solution {
public:
    bool isPossible(vector<int>& a) {
        if (a.size()==1) return a[0] == 1;
        
        priority_queue<int> s(a.begin(), a.end());
        long long t = accumulate(a.begin(), a.end(), 0ll);
        while (s.top() > 1) {
            int x = s.top();
            s.pop();
            int y = s.top();
            
            long long other = t - x;
            if (x <= other) return false;
            
            long long nx = x - (x-y+other-1)/other * other;
            s.push(nx);
            t = t - x + nx;
        }
        return true;
    }
};