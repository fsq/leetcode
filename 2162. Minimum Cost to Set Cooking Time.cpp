class Solution {
public:
    
    int f(int start, int move, int push, int target) {
        int ans = 0;
        char last;
        bool first = true;
        for (auto c : to_string(target)) {
            if (first) {
                if (c == '0') continue;
                ans += push + (c=='0'+start ? 0 : move);
                first = false;
            } else {
                ans += last==c ? push : (move + push);
            }
            last = c;
        }

        return ans;
    }
    
    int minCostSetTime(int start, int move, int push, int targetSeconds) {
        int mm = targetSeconds/60, ss = targetSeconds%60;
        int ans = INT_MAX;
        if (mm<100 && ss<100)
            ans = f(start, move, push, mm*100 + ss);
        --mm;
        ss += 60;
        if (mm<100 && ss<100) return min(ans, f(start, move, push, mm*100+ss));
        return ans;
    }
};