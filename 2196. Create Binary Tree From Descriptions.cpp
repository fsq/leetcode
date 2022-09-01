/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* build(int x, unordered_map<int, vector<int>>& m) {
        auto* t = new TreeNode(x);
        if (!m.count(x)) return t;

        if (m[x][0]) {
            t->left = build(m[x][0], m);
        }
        if (m[x][1]) {
            t->right = build(m[x][1], m);
        }
        return t;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> st;
        for (auto& e : des) {
            if (!m.count(e[0])) m[e[0]] = vector<int>(2);
            m[e[0]][!e[2]] = e[1];
            st.insert(e[1]);
        }

        int root;
        for (auto& pr : m)
            if (!st.count(pr.first)) {
                root = pr.first;
                break;
            }
        
        return build(root, m);
        
    }
};