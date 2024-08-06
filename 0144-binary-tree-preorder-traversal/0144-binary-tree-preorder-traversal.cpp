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

void findPre(TreeNode* root, vector<int> &preorder)
{
    if(root==NULL)
        return;
    preorder.push_back(root->val);
    findPre(root->left,preorder);
   findPre(root->right,preorder);
    
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        findPre(root, preorder);
        return preorder;
        
        
    }
};
//time complexity:-O(N);
//space complexity:-O(N);