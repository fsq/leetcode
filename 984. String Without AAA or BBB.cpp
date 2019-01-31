class Solution {
public:
    string strWithout3a3b(int p, int q) {
        char a = 'a', b = 'b';
        if (p>q) {
            swap(a, b);
            swap(p, q);
        }
        string ans(q, b);
        for (int i=2; i<ans.size(); i+=3) {
            ans.insert(ans.begin()+i, a);
            --p;
        }
        if (p>0) 
            ans.insert(ans.begin(), a), --p;
        if (p>0)
            ans.push_back(a), --p;
        for (int i=0; p>0; i+=4) {
            ans.insert(ans.begin()+i, a);
            --p;
        }
        return ans;
    }
};