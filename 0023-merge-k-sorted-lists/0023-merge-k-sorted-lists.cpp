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
        
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(int i=0;i<n;i++){
            if (lists[i] != nullptr) {
            pq.push({lists[i]->val, lists[i]});
            }
        }

        if(pq.empty())
            return NULL;

        ListNode* result=new ListNode(pq.top().first);
        ListNode* node=pq.top().second;

        if(node->next!=NULL){
            ListNode* temp=pq.top().second;
            pq.pop();
            pq.push({node->next->val,node->next});
        }
        else
            pq.pop();

        node = result;

        while(!pq.empty()){

            auto p=pq.top();
            pq.pop();

            node->next=p.second;
            node=node->next;

            if(p.second->next!=NULL){
                pq.push({p.second->next->val,p.second->next});
            }
        }

        return result;
        

       

    }
};