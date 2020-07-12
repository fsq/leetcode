class Solution {
public:
    string reformatDate(string date) {
        vector<string> m = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        istringstream sin(date);
        string day, month, year;
        sin >> day >> month >> year;
        day = day.substr(0, day.size()-2);
        if (day.size()<2) day = "0" + day;
        for (int i=1; i<=12; ++i)
            if (month==m[i]) {
                month = to_string(i);
                if (month.size()<2) month = "0" + month;
                break;
            }
        return year + "-" + month + "-" + day;
    }
};