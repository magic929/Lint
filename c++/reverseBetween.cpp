#include <iostream>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int val){
            this->val = val;
            this->next =nullptr;
        }
        ListNode(ListNode* head){
            this->next = head;
        }
};

class Solution{
    public:
        void reverse(ListNode *head){
            ListNode *prev = nullptr;
            while(head != nullptr){
                ListNode *tmp = head->next;
                head->next = prev;
                prev = head;
                head = tmp;
            }
        }

        ListNode* findNode(ListNode *node, int k){
            if(node == nullptr){
                return node;
            }
            for(int i = 0; i < k; i++){
                node = node->next;
            }
            return node;
        }

        ListNode *reverseBetween(ListNode *head, int m, int n){
            ListNode *dummy = new ListNode(head);
            ListNode *mth_prev = findNode(dummy, m - 1);
            ListNode *mth = mth_prev->next;
            ListNode *nth = findNode(dummy, n);
            ListNode *nth_next = nth->next;
            nth->next = nullptr;
            reverse(mth);
            mth_prev->next = nth;
            mth->next = nth_next;
            return head;
        }
};

int main(){
    ListNode *head, *tmp;
    int m = 2, n = 4;
    head =  new ListNode(1);
    tmp = head;
    for(int i = 2; i <=5; i++){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    Solution s = Solution();
    ListNode *result = s.reverseBetween(head, m, n);
    while(result != nullptr){
        cout << result->val <<" ";
        result = result->next;
    }
}