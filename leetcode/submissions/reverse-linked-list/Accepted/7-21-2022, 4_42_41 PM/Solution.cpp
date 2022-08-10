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
        if(head == NULL)return head;
        function<ListNode*(ListNode*, ListNode*)> reverse = [&](ListNode* cur, ListNode* prev){
            if (cur->next == NULL) {
                cur->next = prev;
                return cur;
            }  
            ListNode* node = reverse(cur->next, cur);
            cur->next = prev;
            return node;
        };
        head = reverse(head, NULL);
        return head;
    }
};