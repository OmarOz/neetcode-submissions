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
    bool hasCycle(ListNode* head) {
        map<ListNode*,int>freq;
        while(true){
            if(head == nullptr){break;}
            freq[head]++;
            if(freq[head] > 1){return true;}
            head=head->next;
        }
        return false;
    }
};
