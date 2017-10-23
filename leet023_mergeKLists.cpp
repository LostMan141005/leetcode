#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 本题可以使用优先队列(堆排序)、递归合并、合并等方法； 
// 合并和递归合并空间复杂度为 O(1),时间复杂度为(nk log(k)), 优先队列空间复杂度为O(n),时间复杂度同上 
class Solution {
public:
    ListNode* mergeKListsOld(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = mergeTwoLists(head,lists[i]);
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL)
            return l2;
        if (l2 == NULL)
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
    }
    // error result
/*     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head = new ListNode(0), *cur;
        cur = head;
        map<int,ListNode*> mapLists;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) mapLists.insert(make_pair(lists[i]->val,lists[i]));
        }
        while(!mapLists.empty()){
            map<int,ListNode*>::iterator it = mapLists.begin();
            if(it->second->next != NULL) mapLists.insert(make_pair(it->second->next->val,it->second->next));
            
            cur->next = it->second;
            cur = cur->next;
            mapLists.erase(it);
        }
        return head->next;
    } */
    
/*     ListNode *merge2Lists(ListNode *list1, ListNode *list2)
    {
        if(NULL == list1) return list2;
        if(NULL == list2) return list1;
        ListNode res(0);
        ListNode *curRes = &res, *cur1 = list1, *cur2=list2;
        while(cur1 != NULL && cur2 != NULL)
        {
            if(cur1->val < cur2->val)
            {
                curRes->next = cur1;
                cur1 = cur1->next;
            }else
            {
                curRes->next = cur2;
                cur2 = cur2->next;
            }
            curRes = curRes->next;
        }
        curRes->next = cur1 ? cur1 : cur2;
        return res.next;
    }
    ListNode *mergeKLists(ListNode *list[], int size){
         if(0 == size) return NULL;
         if(1 == size) return list[0];
         if(2 == size)
         {
             return merge2Lists(list[0], list[1]);
         }
         int mid = size>>1;
         ListNode *subList1 = mergeKLists(list, mid);
         ListNode *subList2 = mergeKLists(&list[mid], size - mid);
         return merge2Lists(subList1, subList2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(&lists[0], lists.size());
    } */
    
/*     struct cmp
    {
        bool operator() (const ListNode* a,const ListNode* b)
        {
            return a->val  > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        for(auto i:lists)
        {
            if(i) //这句判断很有必要，不能把空的加入队列。比如这组数据：[[],[]]
            {
                pq.push(i);
            }
        }
        if(pq.empty())
        {
            return nullptr;
        }
        ListNode* ans = pq.top();
        pq.pop();
        ListNode* tail = ans;
        if(tail->next)
        {
            pq.push(tail->next);
        }
        while(!pq.empty())
        {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next)
            {
                pq.push(tail->next);
            }
        }
        return ans;
    } */
    
};

int main(){

    return 0;
}