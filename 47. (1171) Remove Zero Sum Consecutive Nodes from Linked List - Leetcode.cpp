/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.
*/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
      dummy->next = head;
      unordered_map <int, ListNode*> m;
      m[0] = dummy;
      int sum = 0;
      while(head){
         sum += head->val;
         m[sum] = head;
         head = head->next;
      }
      head = dummy;
      sum = 0;
      while(head){
         sum += head->val;
         ListNode* temp = m[sum];
         if(temp != head){
            head->next = temp->next;
         }
         head = head->next;
      }
      return dummy->next;
    }
};

/*

0  1 3 6 3 7
-1 0 1 2 

*/