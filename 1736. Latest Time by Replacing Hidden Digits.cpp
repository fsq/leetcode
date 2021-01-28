class Solution {
public:
    string maximumTime(string time) {
        string hour = time.substr(0, 2), min = time.substr(3, 2);
        if (hour == "??")
            hour = "23";
        else if (hour[0] == '?') {
            if (hour[1]>='4')
                hour[0] = '1';
            else 
                hour[0] = '2';
        } else if (hour[1] == '?') {
            if (hour[0]=='2')
                hour[1] = '3';
            else
                hour[1] = '9';
        }
        if (min[0]=='?')
            min[0] = '5';
        if (min[1]=='?')
            min[1] = '9';
        return hour + ":" + min;
    }
};