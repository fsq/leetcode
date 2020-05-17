class Solution {
public:
    
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int dn=2; dn<=n; ++dn) 
            for (int no=1; no<dn; ++no)
                if (__gcd(dn, no)==1)
                    ans.push_back(to_string(no) + "/" + to_string(dn));
        return ans;
    }
};