// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* tempHead;
        if(head == NULL or head->next == NULL)return head;
        function<ListNode*(ListNode*)> recursion = [&](ListNode* cur){
            if(cur->next == NULL){
                tempHead = cur;
                return cur;
            }
            ListNode* node = recursion(cur->next);
            node->next = cur;
            return cur;
        };
        
        ListNode* root = recursion(head); head->next = NULL; root = tempHead;
        return root;
    }
};