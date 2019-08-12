class Solution {
public:
    
    vector<int> ds = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool leap(int x) {
        return (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0));  
    }
    
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        if (leap(year)) ds[1] = 29;
        return accumulate(ds.begin(), ds.begin()+month-1, 0) + day;
    }
};