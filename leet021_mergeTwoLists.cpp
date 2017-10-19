#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = new ListNode(0);
        ListNode *cur;
        cur = head;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
                continue;
            }
            if(l2 == NULL){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
                continue;
            }
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
               
            }else{
                cur->next = l1;
                l1 = l1->next;
                
            }
            cur = cur->next;
        }
        return head->next;
    }
    
/*     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val <= l2->val) 
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    } */
};

int main(){

    return 0;
}