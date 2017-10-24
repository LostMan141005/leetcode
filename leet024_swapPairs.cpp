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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* lhead = new ListNode(0);
        lhead->next = head;
        ListNode* pCur, *pNext, *pTemp;
        pCur = lhead;
        pNext = pCur->next;
        while(pNext){
            if(!pNext->next) break;
            pCur->next = pNext->next;
            pNext->next = pNext->next->next;
            pCur->next->next = pNext;
            pCur = pCur->next->next;
            pNext = pCur->next;
        }
        return lhead->next;
    }
    
/*     // 递归
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    } */
    
};

int main(){

    return 0;
}