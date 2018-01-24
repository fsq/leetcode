class Solution {
public:
    
    // https://leetcode.com/problems/self-crossing/description/
    // O(n) time O(1) space 
    // line intersection (this method works for non-axis-aligned lines)
    
    struct Point {
        int x, y;
        Point() {}
        Point(int _x, int _y):x(_x), y(_y) {}
    };

    struct Edge {
        Point a, b;
        Edge() {}
        Edge(Point a, Point b):a(a), b(b) {}
    };
    
    bool onSegment(Point a, Point b, Point c) {
        if (min(a.x, b.x)<=c.x && c.x<=max(a.x, b.x)
          &&min(a.y, b.y)<=c.y && c.y<=max(a.y, b.y))
            return true;
        return false;
    }

    int cross(Point a, Point b, Point c) {
        int x1 = b.x-a.x, y1 = b.y-a.y, x2 = c.x-a.x, y2 = c.y-a.y;
        return x1*y2 - x2*y1;
    }

    bool intersect(Point p1, Point p2, Point p3, Point p4) {
        int d1 = cross(p1, p2, p3);
        int d2 = cross(p1, p2, p4);
        int d3 = cross(p3, p4, p1);
        int d4 = cross(p3, p4, p2);
        if (d1*d2<0 && d3*d4<0) return true;
        if (d1==0 && onSegment(p1, p2, p3)) return true;
        if (d2==0 && onSegment(p1, p2, p4)) return true;
        if (d3==0 && onSegment(p3, p4, p1)) return true;
        if (d4==0 && onSegment(p3, p4, p2)) return true;
        return false;
    }

    bool isSelfCrossing(vector<int>& lens) {
        vector<Edge> edges(6, Edge());
        int x=0, y=0, dir=0;
        for (int i=0; i<lens.size(); ++i) {
            int tx=x, ty=y, l=lens[i];
            if (dir==0)
                ty += l;
            else if (dir==1)
                tx -= l;
            else if (dir==2)
                ty -= l;
            else 
                tx += l;
            dir = (dir+1) % 4;
            edges[i%6] = Edge(Point(x, y), Point(tx, ty));
            x = tx, y = ty;
            for (int j=i-3; j>=0 && j>=i-5; --j)
                if (intersect(edges[i%6].a, edges[i%6].b, edges[j%6].a, edges[j%6].b)) 
                    return true;
        }
        return false;
    }
};