class Solution {
public:
    // X-a1 >= 0 => X >= a1
    // X-a1+b1-a2 >= 0 => X >= a1-b1+a2
    // For each n, X >= (a1-b1)+...+(an-bn) + bn
    // When ai>=bi, rhs is mono increasing, so let n be #elements that ai>=bi, and bn=max(bi)
    // Let rhs be T
    // When ai<bi, X >= T + a{n+1}
    //             X >= T + a{n+1}-b{n+1}+a{n+2}
    // However,(T+a{n+1}-b{n+1}+a{n+2}) < (T+a{n+2}), so we only need to consider one more element
    // that has max(ai)
    // Overall, X >= (a1-b1)+...+(an-bn) + max(bn, a{n+1})
    long long minimumMoney(vector<vector<int>>& t) {
        long long tot = 0, max_cost = 0, max_b = 0;
        for (auto& pr : t) 
            if (pr[0] >= pr[1]) {
                tot += pr[0] - pr[1];
                max_b = max<long long>(max_b, pr[1]);
            } else 
                max_cost = max<long long>(max_cost, pr[0]);

        return tot + max(max_b, max_cost);
    }
};