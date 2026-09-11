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
    bool checkMirror(TreeNode* p,TreeNode* q){
        if(!p||!q){
            if(!p&&!q) return true;
            return false;
        }
        if(p->val!=q->val) return false;
        bool l=checkMirror(p->left,q->right);
        bool r=checkMirror(p->right,q->left);
        return l&&r;

    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkMirror(root->left,root->right);
    }
};