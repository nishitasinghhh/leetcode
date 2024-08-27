/**
 * Definition for singly-linked list.
 * /struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* leftHead,ListNode* rightHead)
    {
        if(leftHead==NULL) return rightHead;
        if(rightHead==NULL) return leftHead;
        ListNode* t1=leftHead;
            ListNode* t2=rightHead;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<=t2->val)
            {
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else
            {
          temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        while(t1)
        {
            temp->next=t1;
                temp=t1;
                t1=t1->next;
        }
        while(t2)
        {
             temp->next=t2;
                temp=t2;
                t2=t2->next;
        }
        return dummy->next;
    }
    ListNode* findMiddle(ListNode* head)
    { if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* middle=findMiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* lefthead=sortList(left);
        ListNode* righthead=sortList(right);
        return merge(lefthead,righthead);
    }
};