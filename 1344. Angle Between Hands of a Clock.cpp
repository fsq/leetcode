class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = hour%12 + minutes / 60.0;
        double s = abs(a / 12 * 360 - minutes / 60.0 * 360);
        return min(s, 360-s);
    }
};