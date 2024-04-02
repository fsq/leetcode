class Solution {
public:
    int minimumDistance(vector<vector<int>>& ps) {
        multiset<int> A, B;
        for (auto& p : ps) {
            A.insert(p[0]+p[1]);
            B.insert(p[0]-p[1]);
        }
        int ans = INT_MAX;
        for (auto& p : ps) {
            int Ai = p[0]+p[1], Bi = p[0]-p[1];
            auto l=A.begin(), r=prev(A.end());
            if (*l==Ai) 
                ++l;
            else if (*r==Ai)
                --r;
            int Amax = *r-*l;
            l = B.begin(), r=prev(B.end());
            if (*l==Bi) 
                ++l;
            else if (*r==Bi)
                --r;
            int Bmax = *r-*l;
            ans = min(ans, max(Amax, Bmax));
        }
        return ans;
    }
};