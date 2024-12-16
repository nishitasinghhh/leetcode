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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        vector<ListNode*>res;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int numNode=len/k;
        int extra=len%k;
        int i=0;
         temp=head;
        while(temp)
        {
            int curLen=1;
            res.push_back(temp);
            while(curLen<numNode)
            {
                 curLen++;
                temp=temp->next;
               
            }
            if(extra>0 && len>k)
            {
                temp=temp->next;
                extra--;
            }
            ListNode* x=temp->next;
            temp->next=NULL;
            temp=x;
        }
        while(len<k)
        {
            res.push_back(NULL);
           len++;
        }
        return res;
    }
};