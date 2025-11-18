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
    ListNode* swapPairs(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = head->next;
        
        while(head != nullptr && head->next != nullptr)
        {
            ListNode* newNode = head->next->next;
            head->next->next = head;
            if(newNode != nullptr && newNode->next != nullptr)
            {
                head->next = newNode->next;
            }
            else
            {
                head->next = newNode;
            }
            head = newNode;
        }

        return dummy;
        
    }
};