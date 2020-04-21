class Solution {
public:
    string getHappyString(int n, int k) {
        int tot = n==1 ? 3 : 3 * (1<<(n-1));
        if (tot < k) return "";
        if (n==1) return string(1, 'a'+k-1);
        string ans;
        --k;
        for (int i=0; i<n; ++i) {
            int rest = 1<<(n-i-1);
            int d = k / rest;
            char c;
            if (i==0)
                c = 'a' + d;
            else {
                if (ans.back()=='a')
                    c = 'b' + d;
                else if (ans.back()=='b')
                    c = d==0 ? 'a' : 'c';
                else 
                    c = 'a' + d;
            }
            ans.push_back(c);
            k %= rest;
        }
        return ans;
    }
};