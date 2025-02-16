vector<int> p;

class Solution {
public:
    bool IsPrime(int x) {
        for (int i=2; i*i<=x; ++i)
            if (x % i == 0) {
                return false;
            }
        return true;
    }

    void Init() {
        for (long long d=2; d*d<=1e9; ++d) {
            if (IsPrime(d)) {
                p.push_back(d * d);
            }
        }
    }

    int CountSpecial(int r) {
        return upper_bound(p.begin(), p.end(), r) - p.begin();
    }

    int CountNonSpecial(int r) {
        return r - CountSpecial(r);
    }

    int nonSpecialCount(int l, int r) {
        if (p.empty()) {
            Init();
        }
        return CountNonSpecial(r) - CountNonSpecial(l-1);
    }
};