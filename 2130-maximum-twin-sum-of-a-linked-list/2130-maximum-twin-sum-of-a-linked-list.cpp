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
    int pairSum(ListNode* head) {
        
        // get the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the half end
        ListNode* prev = nullptr;
        
        while(slow != nullptr)
        {
            ListNode* nextnode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextnode;
        }

        // dummy head
        ListNode* dummy = head;
        int maxval = INT_MIN;

        while(dummy != nullptr && prev != nullptr)
        {
            maxval = max(maxval, dummy->val + prev->val);
            dummy = dummy->next;
            prev = prev->next;
        }
        
        return maxval;
    }
};