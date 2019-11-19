/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> st;
    
    void dfs(TreeNode* now, int v) {
        st.insert(v);
        if (now->left) dfs(now->left, v * 2 + 1);
        if (now->right) dfs(now->right, v * 2 + 2);
    }
    
    FindElements(TreeNode* root) {
        dfs(root, 0);    
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */