/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    
    queue<TreeNode*> q;
    TreeNode* root;
    
    CBTInserter(TreeNode* _root) {
        root = _root;
        q.push(root);
        while (q.front()->left) {
            q.push(q.front()->left);
            if (q.front()->right) {
                q.push(q.front()->right);
                q.pop();
            } else
                break;
        }
    }
    
    int insert(int v) {
        auto fa = q.front();
        auto now = new TreeNode(v);
        if (!fa->left) 
            fa->left = now;
        else {
            fa->right = now;
            q.pop();
        }
        q.push(now);
        return fa->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */