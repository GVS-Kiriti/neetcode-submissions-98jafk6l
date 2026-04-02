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
    int Gcd(int a, int b){
        int x = 2;
        int ret = 1;
        while(x<=a && x<=b){
            if(a%x==0 && b%x==0){
                ret*=x;
                a=a/x;
                b=b/x;
            }
            else {
                x++;
            }
        }
        return ret;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp && temp->next){
            ListNode* curr = new ListNode(Gcd(temp->val,temp->next->val));
            ListNode* p = temp->next;
            temp->next = curr;
            curr->next = p;
            temp=p;
        }
        return head;
    }
};