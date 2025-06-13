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
        
        priority_queue<int, vector<int>, greater<int>> minh;

        for(int i = 0; i< lists.size(); i++){
            ListNode* curr = lists[i];
            while(curr != NULL){
                minh.push(curr->val);
                curr= curr->next;
            }
        }

        ListNode* ans = new ListNode(0);
        ListNode* curr= ans;

        while(minh.size() > 0){
            ListNode* temp = new ListNode(minh.top());
            curr->next = temp;
            curr = curr->next;
            minh.pop();
        }

        return ans->next;
    }
};