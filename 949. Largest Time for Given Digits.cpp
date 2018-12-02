class Solution {
public:
    string largestTimeFromDigits(vector<int>& a) {
        vector<int> p = {0,1,2,3};
        
        string ans;
        do {
            int h = a[p[0]]*10 + a[p[1]];
            int m = a[p[2]]*10 + a[p[3]];
            if (h>=0 && h<=23 && m>=0 && m<=59) {
                string t = (h<10 ? "0" : "") + to_string(h) + ":" + (m<10 ? "0" : "") + to_string(m);
                if (ans.empty() || t>ans)
                    ans = t;
            }
        } while (next_permutation(p.begin(), p.end()));
        return ans;
    }
};