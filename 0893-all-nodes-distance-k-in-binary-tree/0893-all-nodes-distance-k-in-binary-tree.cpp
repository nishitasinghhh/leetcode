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
void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left)
        {
            parents[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            parents[node->right]=node;
            q.push(node->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parents;
        findParent(root,parents);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dis=0;
        while(!q.empty())
        {
            int size=q.size();
            if(dis++==k)
            break;
            for(int i=0; i<size; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parents[node] && !visited[parents[node]])
                {
                    q.push(parents[node]);
                    visited[parents[node]]=true;
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