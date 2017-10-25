#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(1 == k) return head;
        ListNode* lhead = new ListNode(0);
        lhead->next = head;
        ListNode *l, *r, *tmp, *t, *tail;
        l = lhead;
        r = lhead; 
        int  i = 0;
        while(i++ < k && r) r = r->next;
        if(r == NULL){
            return l->next;
        }else{
            r = r->next;
            tail = l->next;
            l = l->next->next;
            while(l != r){
                tmp = l->next;
                t = lhead->next;
                lhead->next = l;
                l->next = t;
                l = tmp;
            }
            tail->next = reverseKGroup(r,k);
        }
        return lhead->next;
    }
    
/*     ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        int i=0;
        while(p!=NULL&&i<k){
            p=p->next;
            i++;
        }
        if(i==k){
            p=reverseKGroup(p,k);
            while(i-->0){
                ListNode* tmp=head->next;
                head->next=p;
                p=head;
                head=tmp;
            }
            head=p;
        }
        return head;
    } */
    
};

int main(){

    return 0;
}