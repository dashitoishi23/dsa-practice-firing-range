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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* merged = new ListNode;
        ListNode* baseline = new ListNode;

        if (head1 == NULL && head2 == NULL)
            return head1;
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        if (head1->val <= head2->val) {
            merged = head1;
            baseline = head2;
        } else {
            merged = head2;
            baseline = head1;
        }

        int baselineCurr;

        if (merged->next != NULL) {
            while (merged->next != NULL) {
                int curr = merged->next->val;
                while (baseline != NULL) {
                    if (curr >= baseline->val) {
                        ListNode* t = new ListNode;
                        t->val = baseline->val;
                        t->next = merged->next;
                        merged->next = t;
                        baseline = baseline->next;
                        head2 = head2->next;
                        break;
                    }
                    baseline = baseline->next;
                }
                merged = merged->next;
                baseline = head2;
            }
            while (baseline != NULL) {
                merged->next = baseline;
                baseline = baseline->next;
            } // merging did not reach end of head2, append all to head1
            return head1;
        } // merged LL has more than 1 node
        else {
            while (baseline != NULL) {
                merged->next = baseline;
                baseline = baseline->next;
            }
            return merged;
        }
    }
};