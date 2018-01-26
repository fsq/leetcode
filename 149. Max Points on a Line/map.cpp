/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    
    // https://leetcode.com/problems/max-points-on-a-line/description/
    // O(n^2) time O(n) space
    
    int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
    
    int maxPoints(vector<Point>& points) {
        unordered_map<string, int> count;
        int same = 0, ans = 0;
        
        for (int i=0; i<points.size(); ++i) {
            Point& org = points[i];
            same = 1;
            count.clear();
            int max_count = 0;
            for (int j=i+1; j<points.size(); ++j)  {
                Point& now = points[j];
                if (now.x==org.x && now.y==org.y) 
                    ++same;
                else {
                    int dx = org.x - now.x;
                    int dy = org.y - now.y;
                    int len = gcd(abs(dx), abs(dy));
                    dx /= len;
                    dy /= len;
                    if (dx<0) {
                        dx = -dx;
                        dy = -dy;
                    } else if (dx==0)
                        dy = abs(dy);
                    string key = to_string(dx) + ' ' + to_string(dy);
                    max_count = max(max_count, ++count[key]);
                }
            }
            ans = max(ans, max_count+same);
        }
        return ans;
    }
};