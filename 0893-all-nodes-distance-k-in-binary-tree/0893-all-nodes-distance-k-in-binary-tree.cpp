/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void findParent(unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left)
        {
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            parent[node->right]=node;
            q.push(node->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        findParent(parent,root);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int dist=0;
        while(!q.empty())
        {
            int size=q.size();
            if(dist++==k)
            break;
            for(int i=0; i<size; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent[node] && !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};