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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* t1, *t2;
       ListNode *lhead = new ListNode(0);
       lhead->next = head;
       t1 = lhead;
       t2 = lhead;
       int i = 0;
       while(t1->next != NULL){
           if(i++ < n){
               t1 = t1->next;
           }else{
               t1 = t1->next;
               t2 = t2->next;
           }
       }
       t2->next = t2->next->next;
       return lhead->next;
    }
};

int main(){

    return 0;
}