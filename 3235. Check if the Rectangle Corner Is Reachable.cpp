class Solution {
public:
    vector<int> fa;

    int find(int x) {
        return fa[x] == x ? x : fa[x]=find(fa[x]);
    }

    long long Cross(vector<long long>& a, vector<long long>& b) {
        return a[0]*b[1] - a[1]*b[0];
    }

    bool intersect(vector<int>& a, vector<int>& b, int cx, int cy) {
        // a and b intersect
        long long r1 = a[2], r2 = b[2];
        long long dx = abs(a[0] - b[0]);
        long long dy = abs(a[1] - b[1]);
        bool intes = (r1+r2)*(r1+r2) >= dx*dx + dy*dy;
        if (!intes) return false;

        // And intersection point inside rect
        if (a[0]<cx && b[0]<cx) return true;
        if (a[1]<cy && b[1]<cy) return true;

        auto m=a, n=b;
        if (m[0] > n[0]) m.swap(n);
        vector<long long> v1 = {n[0]-m[0], n[1]-m[1]}; // vector from m->n
        vector<long long> v2 = {cx - m[0], cy - m[1]}; // vector from a->corner
        return Cross(v1, v2) >= 0;
    }

    bool Within(vector<int>& c, long long x, long long y) {
        long long dx = c[0] - x, dy = c[1] - y, r = c[2];
        return dx*dx+dy*dy <= r*r;
    }

    // Observation: If circle a, b intersects, they form a "wall" from center a to center b
    // Otherwise, they can be ignored.
    // Construct a line of walls, and check if the wall blocks (0,0) from corner
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& raw) {
        vector<vector<int>> a;
        for (auto& c: raw) {
            if (Within(c, xCorner, yCorner)) return false;
            if (c[0]>=0 && c[1]>=0 && c[0]<xCorner+c[2] && c[1]<yCorner+c[2]) {
                a.push_back(move(c));
            }
        }
        int n = a.size();
        fa.resize(n);    
        iota(fa.begin(), fa.end(), 0);
        for (int i=0; i<a.size(); ++i)
            for (int j=i+1; j<a.size(); ++j)
                if (intersect(a[i], a[j], xCorner, yCorner)) {
                    int x=find(i), y=find(j);
                    fa[x] = y;
                }
        unordered_map<int, bool> l, b, u, r;
        for (int i=0; i<n; ++i) {
            int x = find(i), rd = a[i][2];
            if (a[i][0] <= rd && a[i][1] <= yCorner) l[x] = true;
            if (a[i][1] <= rd && a[i][0] <= xCorner) b[x] = true;
            if (a[i][1]+rd >= yCorner && a[i][0] <= xCorner) u[x] = true;
            if (a[i][0]+rd >= xCorner && a[i][1] <= yCorner) r[x] = true;
        }

        for (int i=0; i<n; ++i)
            if (fa[i] == i) {
                if (l[i] && r[i] || l[i] && b[i] ||
                    u[i] && r[i] || u[i] && b[i])
                    return false;

            }
        return true;
    }
};