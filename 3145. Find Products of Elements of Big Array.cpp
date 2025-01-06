using LL = long long;
class Solution {
public:
    LL count1(LL x) {
        LL b=1, ans=0;
        while (x >= b) {
            auto c = countPow2(x, b);
            ans += c;
            b <<= 1ll;
        }
        return ans;
    }

    LL countPow2(LL x, LL b, LL ind=-1) {
        LL ans = (x+1)/(2*b)*b + max(0ll, (x+1) % (2*b) - b);
        if (ind != -1 && (x & b)) {
            LL rem = count1(x) - ind;
            if (rem > 0) {
                if (__builtin_popcountll(x)-rem <= __builtin_popcountll(x & (b-1))) {
                    --ans;
                }
            }
        }
        return ans;
    }

    LL findNum(LL x) {
        LL l=1, r=1e15;
        while (l < r) {
            auto m = (l+r) >> 1;
            if (count1(m) < x) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    LL pow(LL x, LL p, LL m) {
        if (p==0) return 1;
        if (p==1) return x % m;
        LL s = pow(x, p/2, m);
        if (p & 1) {
            return s * s % m * x % m;
        } else {
            return s * s % m;
        }
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            LL l = findNum(q[0]), r = findNum(q[1]+1), m = q[2];
            LL prod = 1;
            for (int t=0; t<50; ++t) {
                LL b = 1ll << t;
                LL cnt = countPow2(r, b, q[1]+1) - countPow2(l, b, q[0]);
                LL pw = pow(b, cnt, m);
                prod = prod * pw % m;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};