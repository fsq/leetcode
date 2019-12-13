class Solution {
public:
    double x, y, r;
    const double PI = 3.14159265;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        int a = rand() % 360;
        double l = sqrt(((double)rand()/RAND_MAX)) * r;
        return { x + l*sin(a*PI/180), y + l*cos(a*PI/180)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */