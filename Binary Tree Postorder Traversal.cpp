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
    vector<int> postorderTraversal(TreeNode *root) {
        
        vector<int> result;
        result.clear();
        if(root == NULL) return result;
        
        map<TreeNode*, bool> flag;
        stack<TreeNode*> s;
        
        TreeNode *p = root;
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        while(!s.empty())
        {
            p = s.top();
            //p->right exists
            if(p->right != NULL)
            {
                // node p visits first time
                if(flag.find(p) == flag.end())
                {
                    flag[p] = true;
                    p = p->right;
                    while(p)
                    {
                        s.push(p);
                        p = p->left;
                    }
                }
                else
                {
                    // p->right has been traversed
                    result.push_back(p->val);
                    s.pop();
                }
            }
            else
            {
                // no right tree
                result.push_back(p->val);
                s.pop();
            }
        }
        
        return result;
        
    }
};