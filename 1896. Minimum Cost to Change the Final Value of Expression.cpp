class Solution {
public:
    
    vector<int> val;
    
    int calc(int x, char op, int y) {
        return op=='|' ? (x|y) : (x&y);
    }
    
    int eval(const string& s, vector<int>& lf, int l, int r) {
        if (l == r)
            return val[r] = s[l]-'0';
        else if (s[r]==')') {
            if (lf[r] == l) 
                return val[r] = eval(s, lf, l+1, r-1);
            else 
                return val[r] = calc(eval(s, lf, lf[r]+1, r-1), s[lf[r]-1], eval(s, lf, l, lf[r]-2));
        } else {
            return val[r] = calc(eval(s, lf, r, r), s[r-1], eval(s, lf, l, r-2));
        }
    }
    
    int f(const string& s, vector<int>& lf, int l, int r) {
        int ans = 0;
        if (l == r) 
            return 1;
        else if (s[r]==')' && lf[r]==l)
            ans = f(s, lf, l+1, r-1);
        else {
            char op;
            int x, y, fx, fy;
            if (s[r] == ')') {
                op = s[lf[r]-1];
                x = val[r-1], y = val[lf[r]-2];
                fx = f(s, lf, l, lf[r]-2), fy = f(s, lf, lf[r], r);
            } else {
                op = s[r-1];
                x = eval(s, lf, r, r), y = val[r-2];
                fx = 1, fy = f(s, lf, l, r-2);
            }
            if (op == '&') {
                if (x==1 && y==1)
                    ans = min(fx, fy);
                else if (x==0 && y==0)
                    ans = min(fx+fy, 1+min(fx, fy));
                else 
                    ans = 1;
            } else {
                if (x==0 && y==0)
                    ans = min(fx, fy);
                else if (x==1 && y==1)
                    ans = min(fx+fy, 1+min(fx, fy));
                else 
                    ans = 1;
            }
        }
        return ans;
    }
    
    int minOperationsToFlip(string s) {
        vector<int> lf(s.size());
        val.resize(s.size());
        stack<int> stk;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')') {
                lf[i] = stk.top();
                stk.pop();
            }
        eval(s, lf, 0, s.size()-1);
        return f(s, lf, 0, s.size()-1);
    }
};

