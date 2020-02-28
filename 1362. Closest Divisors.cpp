class Solution {
public:
    vector<int> closestDivisors(int x) {
        int q = sqrt(x+1);
        while ((x+1) % q != 0) --q;
        int p = sqrt(x+2);
        while (p>q) {
            if ((x+2) % p==0) break;
            p--;
        }
        int d1 = (x+1)%q==0 ? abs(q-(x+1)/q) : INT_MAX;
        int d2 = (x+2)%p==0 ? abs(p-(x+2)/p) : INT_MAX;
        if (d1<d2)
            return {q, (x+1)/q};
        else 
            return {p, (x+2)/p};
    }
};