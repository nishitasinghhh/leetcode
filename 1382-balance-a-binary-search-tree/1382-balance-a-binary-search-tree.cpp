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
    TreeNode * help2(vector<int>inorder,int start,int end)
    {
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(inorder[mid]);
       root->left= help2(inorder,start,mid-1);
        root->right=help2(inorder,mid+1,end);
        return root;
        
    }
    void help1(TreeNode* root,vector<int> &inorder)
    {
        if(root==NULL)
        {
            return;
        }
        help1(root->left,inorder);
        inorder.push_back(root->val);
        help1(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        help1(root,inorder);
        int n=inorder.size();
        return help2(inorder,0,n-1);
    }
};