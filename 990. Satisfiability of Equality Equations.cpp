class Solution {
public:
    
    vector<int> fa;
    
    int find(int x) {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    
    bool equationsPossible(vector<string>& equ) {
        fa = vector<int>(26);
        iota(fa.begin(), fa.end(), 0);
        vector<string> eq, neq;
        for (auto& e : equ)
            if (e[1]=='!') 
                neq.push_back(move(e));
            else
                eq.push_back(move(e));
        
        for (auto& e : eq) {
            int x = e[0]-'a', y = e[3]-'a';
            int fx=find(x), fy=find(y);
            fa[fx] = fy;
        }
        
        for (auto& e : neq) {
            int fx=find(e[0]-'a'), fy=find(e[3]-'a');
            if (fx==fy) return false;
        }
        return true;
    }   
};