/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class Compare{
        public:
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*> ,Compare>pq;
        for(int i=0;i<lists.size();i++)
        {
           if(lists[i]!=NULL) pq.push(lists[i]);
        }
        
        ListNode* root=new ListNode(0);
        ListNode* tail=root;
        ListNode* temp;
        while(!pq.empty())
        {
            temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;
            
            if(temp->next)
                pq.push(temp->next);
        }
        return root->next;
    }
};