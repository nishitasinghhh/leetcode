/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneUtil(Node* node, unordered_map<Node*,Node*> &mp)
    {
        Node* newNode= new Node(node->val);
        mp[node]=newNode;
        for(auto ng:node->neighbors)
        {
            if(mp.find(ng)==mp.end())
            {
                (newNode->neighbors).push_back(cloneUtil(ng,mp));
            }
            else
            {
                (newNode->neighbors).push_back(mp[ng]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*>mp;
        return cloneUtil(node,mp);
    }
};