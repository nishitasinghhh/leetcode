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
void markParents(unordered_map<TreeNode*,TreeNode*> &parents, TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp->left)
        {
            parents[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            parents[temp->right]=temp;
            q.push(temp->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*>parents;
        markParents(parents,root);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int cur_level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(cur_level++==k) break;
            for(int i=0; i<size; i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !vis[current->left])
                {
                    q.push(current->left);
                    vis[current->left]=1;
                }
                if(current->right && !vis[current->right])
                {
                    q.push(current->right);
                    vis[current->right]=1;
                }
                if(parents[current] && !vis[parents[current]])
                {
                    q.push(parents[current]);
                    vis[parents[current]]=1;
                }
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};