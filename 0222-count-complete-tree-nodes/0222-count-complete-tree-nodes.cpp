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
int findLeftH(TreeNode* root)
{
    int lh=0;
    while(root)
    {
        lh++;
        root=root->left;
    }
    return lh;
}
    int findRightH(TreeNode* root)
{
    int rh=0;
    while(root)
    {
        rh++;
        root=root->right;
    }
    return rh;
}
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=findLeftH(root);
        int rh=findRightH(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
//time complexity:O(logn^2);
//space complexity:-O(logn)