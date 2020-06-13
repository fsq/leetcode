/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(Node* x, int d) {
        if (!x) return;
        if (ans.size()<d) 
            ans.push_back({x->val}); 
        else
            ans[d-1].push_back(x->val);
        for (auto y : x->children) 
            dfs(y, d+1);
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 1);
        return ans;
    }
};