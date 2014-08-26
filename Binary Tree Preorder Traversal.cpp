/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        
        vector<int> result;
        result.clear();
        if(root == NULL) return result;
        stack<TreeNode*> s;
        
        TreeNode *p = root;
        // preoreder, FILO, push right first
        if(p->right != NULL) s.push(p->right);
        if(p->left != NULL) s.push(p->left);
        result.push_back(p->val);
        
        while(!s.empty())
        {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            if(p->right != NULL) s.push(p->right);
            if(p->left != NULL) s.push(p->left);
        }
        
        return result;
        
    }
};