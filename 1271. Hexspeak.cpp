class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        string s;
        while (n) {
            int r = n % 16;
            n /= 16;
            if (r>=10) 
                s.push_back('A' + (r-10));
            else if (r==0)
                s.push_back('O');
            else if (r==1)
                s.push_back('I');
            else
                return "ERROR";
        }
        reverse(s.begin(), s.end());
        return s;
    }
};