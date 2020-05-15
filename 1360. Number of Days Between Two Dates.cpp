class Solution {
public:
    
    vector<int> ml = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool leap(int year) {
        return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
    }
    
    int yl(int y) {
        return 365 + leap(y);
    }
    
    int from1971(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        int ans = 0;
        if (leap(y)) ml[2] = 29; else ml[2] = 28;
        for (int i=1971; i<y; ++i) ans += yl(i);
        while (m--) ans += ml[m];
        return ans + d;
    }
    
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) swap(date1, date2);
        return from1971(date2) - from1971(date1);
    }
};