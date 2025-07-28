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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
       if(k==0)return NULL;

        while(k>1)
         {
            ListNode*first=lists.back();
            lists.pop_back();
            ListNode*second=lists.back();
            lists.pop_back();
         
            ListNode*head3=new ListNode();
           ListNode*temp=head3;
          
            while(first!=NULL&&second!=NULL)
            {
                if(first->val<second->val)
                 {
                    temp->next=first;
                    first=first->next;
                    // i++;
                    temp=temp->next;
                 }
                 else
                 {
                    temp->next=second;
                    second=second->next;
                    // j++;
                    temp=temp->next;
                 }
            }
            while(first!=NULL)
            {
                    temp->next=first;
                    first=first->next;
                    // i++;
                    temp=temp->next;
            }
            while(second!=NULL)
             {
                    temp->next=second;
                    second=second->next;
                    // j++;
                    temp=temp->next;
             }
             temp->next=NULL;
            lists.push_back(head3->next);
            // delete head3;
            // delete temp;
            k--;
         }
         ListNode*result=lists.back();
         return result;

    }
};